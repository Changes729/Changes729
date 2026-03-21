> 原文链接：https://www.scaledrone.com/blog/webrtc-tutorial-simple-video-chat/

# WebRTC Tutorial: Simple video chat

**01 Signaling 信令部分**

As explained before, signaling is used for the discovery and negotiation process of WebRTC peers. Let's use Scaledrone as our signaling server because it lets us use WebRTC without doing any server programming. However, if you wish to write your own signaling server, this tutorial will still work fine.

如前所述，信令用于WebRTC对等体的发现和协商过程。让我们使用Scaledrone作为我们的信令服务器，因为它允许我们使用WebRTC而无需进行任何服务器编程。但是，如果您希望编写自己的信令服务器，本教程仍然可以很好地工作。

Scaledrone works by letting you subscribe to a room, it then broadcasts messages sent into that room to all subscribed users. This makes Scaledrone ideal for WebRTC signaling.

Scaledrone的工作原理是让您订阅一个房间，然后将发送到该房间的消息广播给所有订阅的用户。这使得Scaledrone成为WebRTC信令的理想选择。



**ICE 部分**

The `RTCPeerConnection` instance `pc` represents a WebRTC connection between the local computer and a remote peer.

`RTCPeerConnection`实例`pc`表示本地计算机和远程对等体之间的WebRTC连接。

**RTCPeerConnection emit handling **

**RTCPeerConnection发出处理**

- **`onicecandidate`** returns locally generated ICE candidates for signaling to other users. We pass it on to our signaling service.

  `onicecandidate`返回本地生成的ICE候选，用于向其他用户发送信号。我们把它传递给我们的信号服务。

- **`onnegotiationneeded`** is triggered when a change has occurred which requires session negotiation. This event starts the createOffer process and is only handled by the user that is an offerer.

  `onnegotiationneeded`在发生需要会话协商的更改时触发。此事件将启动“拒绝提供”进程，并且仅由提供者用户处理。

- **`onaddstream`** returns the remote video and audio stream of the remote user. Set that as the source of the remote video element.

  `onaddstream`返回远程用户的远程视频和音频流。将其设置为远程视频元素的源。

```js
let pc;
function startWebRTC(isOfferer) {
 pc = new RTCPeerConnection(configuration);
 
 // 'onicecandidate' notifies us whenever an ICE agent needs to deliver a
 // message to the other peer through the signaling server
 pc.onicecandidate = event => {
   if (event.candidate) {
     sendMessage({'candidate': event.candidate});
   }
 };
 
 // If user is offerer let the 'negotiationneeded' event create the offer
 if (isOfferer) {
   pc.onnegotiationneeded = () => {
     pc.createOffer().then(localDescCreated).catch(onError);
   }
 }
 
 // When a remote stream arrives display it in the #remoteVideo element
 pc.onaddstream = event => {
   remoteVideo.srcObject = event.stream;
 };
 
 navigator.mediaDevices.getUserMedia({
   audio: true,
   video: true,
 }).then(stream => {
   // Display your local video in #localVideo element
   localVideo.srcObject = stream;
   // Add your stream to be sent to the conneting peer
   pc.addStream(stream);
 }, onError);
}
```



To listen to messages from the signaling service define a `startListentingToSignals` function. We are interested in two types of messages; these are the same messages that we send out in the code above:

为了监听来自信令服务的消息，定义了一个`startListentingToSignals`函数。我们对两种类型的消息感兴趣;这些消息与我们在上面的代码中发送的消息相同：

- `message.sdp` - Session Description Protocol is a string describing the local end of the remote connection. After receiving an offer or answer from another peer we can answer it.

  `message.sdp` -会话描述协议是描述远程连接的本地端的字符串。在收到来自另一个对等体的报价或回答后，我们可以回答它。

- `message.candidate` - add the new ICE candidate to our connections remote description.

  `message.candidate` -将新的ICE候选添加到我们的连接远程描述中。

```js
function startListentingToSignals() {
 // Listen to signaling data from Scaledrone
 room.on('data', (message, client) => {
   // Message was sent by us
   if (!client || client.id === drone.clientId) {
     return;
   }
   if (message.sdp) {
     // This is called after receiving an offer or answer from another peer
     pc.setRemoteDescription(new RTCSessionDescription(message.sdp), () => {
       // When receiving an offer lets answer it
       if (pc.remoteDescription.type === 'offer') {
         pc.createAnswer().then(localDescCreated).catch(onError);
       }
     }, onError);
   } else if (message.candidate) {
     // Add the new ICE candidate to our connections remote description
     pc.addIceCandidate(
       new RTCIceCandidate(message.candidate), onSuccess, onError
     );
   }
 });
}
```



`localDescCreated` gets called when creating an offer and when answering one. It updates the local description of the connection.
`localDescCreated`在创建报价和回答报价时被调用。它更新连接的本地描述。

```js
function localDescCreated(desc) {
 pc.setLocalDescription(
   desc,
   () => sendMessage({'sdp': pc.localDescription}),
   onError
 );
}
```