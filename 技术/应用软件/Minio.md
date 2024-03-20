# Minio

```go
// ObjectPartInfo Info of each part kept in the multipart metadata
// file after CompleteMultipartUpload() is called.
type ObjectPartInfo struct {
	ETag       string            `json:"etag,omitempty"`
	Number     int               `json:"number"`
	Size       int64             `json:"size"`       // Size of the part on the disk.
	ActualSize int64             `json:"actualSize"` // Original size of the part without compression or encryption bytes.
	ModTime    time.Time         `json:"modTime"`    // Date and time at which the part was uploaded.
	Index      []byte            `json:"index,omitempty" msg:"index,omitempty"`
	Checksums  map[string]string `json:"crc,omitempty" msg:"crc,omitempty"` // Content Checksums
}
```

文本的标签就是`Key-Val`字符串。



## upload 方法

```go
func configureServerHandler(endpointServerPools EndpointServerPools) (http.Handler, error) {
	// Initialize router. `SkipClean(true)` stops minio/mux from
	// normalizing URL path minio/minio#3256
	router := mux.NewRouter().SkipClean(true).UseEncodedPath()

    ...
    
	// Add server metrics router; 这里注册一些「指标」函数
	registerMetricsRouter(router)
    
    ... 
    
	return router, nil
}
```

```go
func registerMetricsRouter(router *mux.Router) {
	// metrics router
	metricsRouter := router.NewRoute().PathPrefix(minioReservedBucketPath).Subrouter()
	authType := strings.ToLower(env.Get(EnvPrometheusAuthType, string(prometheusJWT)))

	auth := AuthMiddleware
	if prometheusAuthType(authType) == prometheusPublic {
		auth = NoAuthMiddleware
	}
	metricsRouter.Handle(prometheusMetricsPathLegacy, auth(metricsHandler()))
	metricsRouter.Handle(prometheusMetricsV2ClusterPath, auth(metricsServerHandler()))
    // 这里注册 bucket 的处理函数
	metricsRouter.Handle(prometheusMetricsV2BucketPath, auth(metricsBucketHandler()))
	metricsRouter.Handle(prometheusMetricsV2NodePath, auth(metricsNodeHandler()))
	metricsRouter.Handle(prometheusMetricsV2ResourcePath, auth(metricsResourceHandler()))
}
```

```go
func metricsBucketHandler() http.Handler {
    // 有一个 bucketCollector 搜集器
	return metricsHTTPHandler(bucketCollector, "handler.MetricsBucket")
}

func init() {
    ...
    
    // bucketMetricsGroups 由 getBucketUsageMetrics() 构成
	bucketMetricsGroups := []*MetricsGroup{
		getBucketUsageMetrics(),
		getHTTPMetrics(true),
		getBucketTTFBMetric(),
	}
    
    ... 
    
    // bucketCollector 由 bucketMetricsGroups 变换而来
  	bucketCollector = newMinioBucketCollector(bucketMetricsGroups)   
}
```

```go
func getBucketUsageMetrics() *MetricsGroup {
    ...
    
    // 在这里添加了 upload 方法
    metrics = append(metrics, Metric{
							Description:          getBucketRepLatencyMD(),
							HistogramBucketLabel: "range",
							Histogram:            stat.Latency.getUploadLatency(),
							VariableLabels:       map[string]string{"bucket": bucket, "operation": "upload", "targetArn": arn},
						})
}
```

minio 使用了 [prometheus 库](https://pkg.go.dev/github.com/prometheus/client_golang/prometheus)
