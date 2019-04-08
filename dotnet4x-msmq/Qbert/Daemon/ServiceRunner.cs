using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Messaging;
using System.IO;
using System.Diagnostics;

namespace Daemon
{
    class ServiceRunner
    {
        private bool running = true;
        public void Run()
        {
            running = true;
            Console.WriteLine("starting");

            string queueName = ".\\Private$\\TestQueue";

            if (!MessageQueue.Exists(queueName))
            {
                MessageQueue.Create(queueName).SetPermissions("Everyone", MessageQueueAccessRights.FullControl);
            }

            using (MessageQueue queue = new MessageQueue(queueName))
            {
                while (running)
                {
                    Message message = queue.Receive();

                    using (Stream stream = message.BodyStream)
                    {
                        string messageText = new StreamReader(stream).ReadToEnd();

                        using (EventLog eventLog = new EventLog("Application"))
                        {
                            eventLog.Source = "Qbert";
                            eventLog.WriteEntry(messageText, EventLogEntryType.Information, 2, 1);
                        }
                    }
                }

                queue.Close();
            }
        }

        public void Stop()
        {
            running = false;
        }
    }
}