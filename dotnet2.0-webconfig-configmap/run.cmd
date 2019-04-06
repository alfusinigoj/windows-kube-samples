
IF EXIST "C:\config\Web.config" (
    COPY /Y C:\config\Web.config C:\inetpub\wwwroot\Web.config
) 

C:\ServiceMonitor.exe w3svc
