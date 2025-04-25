> from：https://github.com/neuracle/neuracle-api/blob/main/Neuracle_API_PY/example_online_fetch_data.py

# example_online_fetch_data.py

```python
dsi = dict(device_name='DSI-24', hostname='127.0.0.1', port=8844,
           srate=300,
           chanlocs=['P3', 'C3', 'F3', 'Fz', 'F4', 'C4', 'P4', 'Cz', 'CM', 'A1', 'Fp1', 'Fp2', 'T3', 'T5', 'O1',
                     'O2', 'X3', 'X2', 'F7', 'F8', 'X1', 'A2', 'T6', 'T4', 'TRG'], n_chan=25)
```

`dsi`是脑电。

```python
thread_data_server = DataServerThread(device=target_device['device_name'], n_chan=target_device['n_chan'],
                                          srate=target_device['srate'], t_buffer=time_buffer)
```

```python
nPoints= int(np.round(self.t_buffer*self.srate))
self.ringBuffer = RingBuffer(self.n_chan, nPoints) # initiate the ringbuffer class
```

```python
class RingBuffer():
    def __init__(self,n_chan,n_points):
        self.n_chan = n_chan
        self.n_points = n_points
        self.buffer = np.zeros((n_chan, n_points))
        self.currentPtr = 0
        self.nUpdate = 0
```

从代码中可以看到，buffer是`t_buffer * srate * n_chan`得出的，也就是`时间*数据率*通道数`

```python
def getData(self):
  data = np.hstack([self.buffer[:,self.currentPtr:], self.buffer[:,:self.currentPtr]])
  return data
```

从中可以看出，只要是取数据，就一定是全取的。所以有可能为空值。

```python
 while not flagstop:  # get data in one second step
    nUpdate = thread_data_server.GetDataLenCount()
    if nUpdate > (1 * target_device['srate'] - 1):
      N += 1
      data = thread_data_server.GetBufferData()
      thread_data_server.ResetDataLenCount()
      # print(data.sum(axis=1))
      time.sleep(1)
      if N > 10:
        flagstop = True
```

所以这个代码本质上是用10秒的时间获取一个3s的数据。

