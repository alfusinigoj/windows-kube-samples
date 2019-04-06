# Dotnet 2.0 WebForms

Here lies a simple ASP.NET 2.0 WebForms application. This sample demonstrates injecting a `Web.config` file into an application by way of a ConfigMap.

On Windows workers volumes can only be mounted on directories rather than also onto files so there was no way to inject the `Web.config` directly into the application directory (a requirement for ASP.NET web apps). Instead, the ConfigMap is mounted to `C:\config` and the `Web.config` is then copied into the application *BEFORE* IIS starts, thus not causing an application restart.

## Dockerfile

The `Dockerfile` assume that you've published the application to the `bin\Release\Publish` folder.

The `Dockerfile` also assumes that your solution is named WebConfigConfigMap and is placed at the same level as the `Dockerfile`.

## configmap.yml

The ConfigMap containing our cloudy Web.config is located in `configmap.yml`. As is the case with all ConfigMaps this must be created before the deployment. Alternatively the spec for the ConfigMap could be included into the same YAML file as the deployment.

## run.cmd

This is the custom entrypoint for the application. It's responsible for copying the config into the application's directory.
