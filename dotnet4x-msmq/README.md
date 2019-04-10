# MSMQ
Here's an example of a pod hosting a WebAPI front end and a pod hosting a Windows Service backend that communication with each other via MSMQ.

# api.Dockerfile
The container hosting the WebAPI front-end. MSMQ is installed into the base IIS container.

# daemon.Dockerfile
The container hosting the Windows Service backend. MSMQ is installed into the base servercore container. Port 1803 is exposed in order to receive messages from the frontend. 

# Web.config

Configure <YOUR SERVICE NAME> and <YOUR NAMESPACE> with the correct values for your deployment. It doesn't seem like the search domain is working on the Windows sandbox at this time so manual configuration is necessary.

# Testing through KubeProxy

Assuming you have kubeproxy running with `kubectl proxy` you can

`curl -X POST http://localhost:8001/api/v1/namespaces/<YOUR NAMESPACE>/pods/<YOUR API POD NAME>/proxy/api/message -H "Content-Type: application/x-www-form-urlencoded" --data 'message=data1'|more`

You will see the message show up in the EventLog of the daemon with

`Get-EventLog -LogName Application -Source Qbert`