using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace SelfHostedWCFService
{
    public class ServiceRunner
    {
        private ServiceHost host;
        public void Run()
        {
            Uri baseAddress = new Uri("http://0.0.0.0:8080/");

            this.host = new ServiceHost(typeof(PKSWCFService), baseAddress);
            ServiceMetadataBehavior smb = new ServiceMetadataBehavior();
            smb.HttpGetEnabled = true;
            smb.MetadataExporter.PolicyVersion = PolicyVersion.Policy15;
            host.Description.Behaviors.Add(smb);
            host.Open();
        }

        public void Stop()
        {
            this.host.Close();
        }
    }
}
