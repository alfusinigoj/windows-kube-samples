using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Messaging;
using System.Configuration;

namespace API.Controllers
{
    public class MessageFields {
        public string Message { get; set; }
    }
    public class MessageController : ApiController
    {
        public void Post([FromBody]MessageFields message)
        {
            Console.WriteLine(message.Message);

            string queueName = ConfigurationManager.AppSettings["remote_queue"];

            using (MessageQueue queue = new MessageQueue(queueName))
            {
                queue.Send(message.Message);
                queue.Close();
            }
        }
    }
}
