FROM mcr.microsoft.com/dotnet/framework/aspnet:3.5
SHELL ["powershell", "-Command", "$ErrorActionPreference = 'SilentlyContinue'; $ProgressPreference = 'SilentlyContinue';"]

EXPOSE 80

WORKDIR /inetpub/wwwroot
COPY Dotnet2WebForms/Dotnet2WebForms/bin/Release/Publish/bin/* ./bin/
COPY Dotnet2WebForms/Dotnet2WebForms/bin/Release/Publish/* ./
