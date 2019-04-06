# Dotnet 2.0 WebForms

Here lies a simple ASP.NET 2.0 WebForms application. This sample demonstrates dockerizing the applications by adding a simple, hand-rolled `Dockerfile` which requires no modifications to the enclosed project. 

An alternate strategy that would require slight modification to the project would be to Dockerize the application within VisualStudio itself. In that case, however, the Dockerfile may require some modification (i.e. changing the base image) in order to operate in a modern K8s environment. If you were to take this approach you could use the enclosed `Dockerfile` as a reference for critical information such as the correct base image.

## Dockerfile

The `Dockerfile` assume that you've published the application to the `bin\Release\Publish` folder.

The `Dockerfile` also assumes that your solution is named Dotnet2WebForms and is placed at the same level as the `Dockerfile`.

## TODO
