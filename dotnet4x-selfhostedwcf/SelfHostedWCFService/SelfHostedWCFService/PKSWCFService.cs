using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;

namespace SelfHostedWCFService
{
    [ServiceContract]
    public interface IPKSWCFService {
        [OperationContract]
        string Ping();
    }
    public class PKSWCFService : IPKSWCFService
    {
        public string Ping()
        {
            return "Pong";
        }
    }
}
