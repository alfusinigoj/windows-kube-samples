# MSMQ
Here's an example of a pod hosting a WebAPI front end and a pod hosting a Windows Service backend that communication with each other via MSMQ.

# api.Dockerfile
The container hosting the WebAPI front-end. MSMQ is installed into the base IIS container.

# daemon.Dockerfile
The container hosting the Windows Service backend. MSMQ is installed into the base servercore container. Port 1803 is exposed in order to receive messages from the frontend. 

# Qbert/API/Controlers/MessageController.cs

Replace or configure <URL OF DAEMON SERVICE> with the KubeDNS entry for the dotnet4qbertdaemon service.
