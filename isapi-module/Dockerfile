FROM microsoft/iis
SHELL ["powershell", "-command"]

WORKDIR /

# Install the ISAPI Windows feature
RUN Install-WindowsFeature Web-ISAPI-Ext

# Install the **64-bit** VC++ runtime
RUN Invoke-WebRequest -Uri https://aka.ms/vs/15/release/vc_redist.x64.exe -OutFile vc_redist.x64.exe
RUN Start-Process -filepath ./vc_redist.x64.exe  -ArgumentList "/install", "/passive", "/norestart", "'/log a.txt'" -PassThru | Wait-Process

COPY PKSISAPI/x64/Release/PKSISAPI.dll /Inetpub/wwwroot/isapi/

# Configure IIS to execute our module
RUN "c:/Windows/System32/inetsrv/appcmd.exe set config -section:system.webServer/security/isapiCgiRestriction /`+\"[path='C:\Inetpub\wwwroot\isapi\PKSISAPI.dll',allowed='True',groupId='PivotalGroup',description='PKS Extension']\" /commit:apphost"
RUN "c:/Windows/System32/inetsrv/appcmd.exe set config /section:handlers /`+\"[name='PKSIsapiExtension',path='PKSISAPI.dll',verb='GET,POST',modules='IsapiModule',scriptProcessor='C:\Inetpub\wwwroot\isapi\PKSISAPI.dll']\" /commit:apphost"

# Uncomment the following to configure IIS to not supress error messages 
#RUN "c:/Windows/System32/inetsrv/appcmd.exe set config \"Default Web Site\" /section:system.webServer/httpErrors /errorMode:Detailed"

ENTRYPOINT [ "ServiceMonitor.exe", "w3svc" ]

EXPOSE 80
