FROM microsoft/iis
SHELL ["powershell", "-command"]
EXPOSE 80

# Install ASP
RUN Install-WindowsFeature Web-ASP; 

# Clean out default site
RUN powershell -NoProfile -Command Remove-Item -Recurse C:\inetpub\wwwroot\*

WORKDIR /inetpub/wwwroot
COPY wwwroot/* .
