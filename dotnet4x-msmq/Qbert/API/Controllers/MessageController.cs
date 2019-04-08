using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Messaging;

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

            string queueName = "FormatName:Direct=TCP:127.0.0.1\\Private$\\TestQueue";

            using (MessageQueue queue = new MessageQueue(queueName))
            {
                queue.Send(message.Message);
                queue.Close();
            }
        }
    }
}
