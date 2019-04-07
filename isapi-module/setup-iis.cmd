c:/Windows/System32/inetsrv/appcmd.exe set config "Default Web Site" /section:system.webServer/httpErrors /errorMode:Detailed
c:/Windows/System32/inetsrv/appcmd.exe set config -section:system.webServer/security/isapiCgiRestriction /+"[path='C:\Inetpub\wwwroot\isapi\PKSISAPI.dll',allowed='True',groupId='PivotalGroup',description='PKS Extension']" /commit:apphost
c:/Windows/System32/inetsrv/appcmd.exe set config /section:handlers /+[name='PKSIsapiExtension',path='PKSISAPI.dll',verb='GET,POST',modules='IsapiModule',scriptProcessor='C:\Inetpub\wwwroot\isapi\PKSISAPI.dll'] /commit:apphost
