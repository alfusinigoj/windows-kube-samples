FROM mcr.microsoft.com/dotnet/framework/aspnet:4.8

ADD Library/Library/bin/Release/Library.dll /Library.dll
ADD machine.config /Windows/Microsoft.NET/Framework64/v4.0.30319/Config/machine.config
ADD gac.ps1 /gac.ps1
RUN /gac.ps1
COPY Consumer/Consumer/bin/Release/publish/ /inetpub/wwwroot