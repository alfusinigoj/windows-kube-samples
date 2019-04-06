FROM mcr.microsoft.com/dotnet/framework/aspnet:3.5
SHELL ["powershell", "-Command", "$ErrorActionPreference = 'SilentlyContinue'; $ProgressPreference = 'SilentlyContinue';"]

EXPOSE 80

COPY run.cmd /

WORKDIR /inetpub/wwwroot
COPY WebConfigConfigMap/WebConfigConfigMap/bin/Release/Publish/bin/* ./bin/
COPY WebConfigConfigMap/WebConfigConfigMap/bin/Release/Publish/* ./

ENTRYPOINT [ "c:\\run.cmd" ]
