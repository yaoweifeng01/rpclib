#include "rpc/client.h"

#include <iostream>
#include <thread>

const int sleeptime_ms = 500;
bool g_sleep = true;
int max_server_count = 8;
class Cyber_ge_adapter
{
    public:
        int frame = 0;
        Cyber_ge_adapter(const std::string& ip, int port)
        {
            //client_ = std::make_shared<rpc::client>(ip, port);
            vClient_.resize(max_server_count);
            for (int i=0; i < vClient_.size(); i++)
            {
                vClient_[i] = std::make_shared<rpc::client>(ip, port++);
            }
        }
        ~Cyber_ge_adapter()
        {
            for (int i=0; i < vClient_.size(); i++)
            {
                vClient_[i] = nullptr;
            }
        }

        // millisecond:毫秒 1s = 1000毫秒
        // microseconds:微秒 1s = 1000 000 微妙
        void ProcLocalization()
        {
            while (true)
            {
                //try
                {
                    auto start = std::chrono::steady_clock::now();
                    //ge_server::ByteResponse result(client_->call("getlocalization").as<ge_server::ByteResponse>());
                    auto result = vClient_[0]->call("add1", 3,4).as<int>();
                    //std::this_thread::sleep_for(std::chrono::milliseconds (100));
                    auto end = std::chrono::steady_clock::now();

                    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "ms \n";
                    //std::cout << "result:" << result << std::endl;
                }
                // catch (const std::future_error& e)
                // {
                //     std::cout << "add catch error code:" << e.code() << "\nMessage: " << e.what()<< std::endl;
                // }
                // catch (...)
                // {
                //     std::cout << "ProcLocalization all" << std::endl;
                // }
                // std::cout << "ProcLocalization > " <<  result.byte_data_uint8.size() << std::endl;
                // if (result.byte_data_uint8.empty())
                // {
                //     // std::cout << "ProcLocalization: data is null" << std::endl;
                //     if (g_sleep)
                //     {
                //         std::this_thread::sleep_for(std::chrono::milliseconds(10));
                //     }
                //     continue;
                // }
                // std::string pb_str(result.byte_data_uint8.begin(), result.byte_data_uint8.end());
                // // /std::cout << frame++ << std::endl;
                // PublishLocalization(pb_str.c_str(), pb_str.size());
            }
        }

        void ProcPlanningMessage()
        {
            while (true)
            {
                std::string planningMessage;
                int maxSize = 204800;
                
                try {
                    //bool result = client_->call("setplanningmessage", planningMessage.c_str(), planningMessage.size()).as<bool>();
                    auto result = vClient_[1]->call("add2", 3,4).as<int>();
                }
                catch (const std::future_error& e)
                {
                    std::cout << "add2 catch error code:" << e.code() << "\nMessage: " << e.what()<< std::endl;
                }
                catch (...)
                {
                    std::cout << "ProcPlanningMessage all" << std::endl;
                }
            }
        }

        
        void ProcPerceptionObstacles()
        {
            while (true)
            {
                try{
                    //ge_server::ByteResponse result(client_->call("getperceptionobstacles").as<ge_server::ByteResponse>());
                    auto result = vClient_[2]->call("add3", 3,4).as<int>();
                }
                catch (const std::future_error& e)
                {
                    std::cout << "add3 catch error code:" << e.code() << "\nMessage: " << e.what() << "; frame=" << frame ++ << std::endl;
                }
                catch (...)
                {
                    std::cout << "ProcPerceptionObstacles all" << std::endl;
                }
                // if (result.byte_data_uint8.empty())
                // {
                //     //std::cout << "ProcPerceptionObstacles: data is null" << std::endl;
                //     if (g_sleep)
                //     {
                //         std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime_ms));
                //     }
                //     continue;
                // }
                // // std::cout << "ProcPerceptionObstacles > " <<  result.byte_data_uint8.size() << "; " << frame ++ << std::endl;
                // std::string pb_str(result.byte_data_uint8.begin(), result.byte_data_uint8.end());
                // PublishPerceptionObstacles(pb_str.c_str(), pb_str.size(), false);
            }
        }

        void ProcPerceptionObstacles_gt()
        {
            while (true)
            {
                try{
                //ge_server::ByteResponse result(client_->call("getperceptionobstacles_gt").as<ge_server::ByteResponse>());
                auto result = vClient_[3]->call("add4", 3,4).as<int>();
                }
                catch (const std::future_error& e)
                {
                    std::cout << "add4 catch error code:" << e.code() << "\nMessage: " << e.what()<< std::endl;
                }
                catch (...)
                {
                    std::cout << "ProcPerceptionObstacles_gt all" << std::endl;
                }
                // if (result.byte_data_uint8.empty())
                // {
                //     //std::cout << "ProcPerceptionObstacles_gt: data is null" << std::endl;
                //     if (g_sleep)
                //     {
                //         std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime_ms));
                //     }
                //     continue;
                // }
                // std::string pb_str(result.byte_data_uint8.begin(), result.byte_data_uint8.end());
                // PublishPerceptionObstacles(pb_str.c_str(), pb_str.size(), true);
            }
        }

        void PorcLidar()
        {
            while (true)
            {
                try{
                //ge_server::ByteResponse2 result(client_->call("getlidar").as<ge_server::ByteResponse2>());
                auto result = vClient_[4]->call("add5", 3,4).as<int>();
                }
                catch (const std::future_error& e)
                {
                    std::cout << "add5 catch error code:" << e.code() << "\nMessage: " << e.what()<< std::endl;
                }
                catch (...)
                {
                    std::cout << "lidar all" << std::endl;
                }
                // if (result.byte_data_uint8.empty() || result.byte2_data_uint8.empty())
                // {
                //     // std::cout << "PorcLidar: data is null" << std::endl;
                //     if (g_sleep)
                //     {
                //         std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime_ms));
                //     }
                //     continue;
                // }
                // std::string pb_str(result.byte_data_uint8.begin(), result.byte_data_uint8.end());
                // std::string pb_header_str(result.byte2_data_uint8.begin(), result.byte2_data_uint8.end());
                // PublishLidar(pb_str.c_str(), pb_str.size(), pb_header_str.c_str(), pb_header_str.size());
            }
        }

        void PorcCamera()
        {
            while (true)
            {
                try{
                //ge_server::ByteResponse2 result(client_->call("getcamera").as<ge_server::ByteResponse2>());
                auto result = vClient_[5]->call("add6", 3,4).as<int>();
                }
                catch (const std::future_error& e)
                {
                    std::cout << "add6 catch error code:" << e.code() << "\nMessage: " << e.what()<< std::endl;
                }
                catch (...)
                {
                    std::cout << "lidar all" << std::endl;
                }
                // if (result.byte_data_uint8.empty() || result.byte2_data_uint8.empty())
                // {
                //     // std::cout << "PorcCamera: data is null" << std::endl;
                //     if (g_sleep)
                //     {
                //         std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime_ms));
                //     }
                //     continue;
                // }
                // //std::cout << "PorcCamera > " <<  result.byte_data_uint8.size() << "; frame: " + frame << std::endl;
                // std::string pb_str(result.byte_data_uint8.begin(), result.byte_data_uint8.end());
                // std::string pb_header_str(result.byte2_data_uint8.begin(), result.byte2_data_uint8.end());
                // PublishCamera(pb_str.c_str(), pb_str.size(), pb_header_str.c_str(), pb_header_str.size());
                //std::cout << "PorcCamera " << pb_header_str << std::endl;
            }
        }

        void ProcTF()
        {
            while (true)
            {
                try{
                //ge_server::ByteResponse result(client_->call("gettf").as<ge_server::ByteResponse>());
                auto result = vClient_[6]->call("add7", 3,4).as<int>();
                }
                catch (const std::future_error& e)
                {
                    std::cout << "add7 catch error code:" << e.code() << "\nMessage: " << e.what()<< std::endl;
                }
                catch (...)
                {
                    std::cout << "ProcTF all" << std::endl;
                }
                // if (result.byte_data_uint8.empty())
                // {
                //     // std::cout << "ProcTF: data is null" << std::endl;
                //     if (g_sleep)
                //     {
                //         std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime_ms));
                //     }
                //     continue;
                // }
                // std::string pb_str(result.byte_data_uint8.begin(), result.byte_data_uint8.end());
                // PublishTF(pb_str.c_str(), pb_str.size());

            }
        }

        void ProcTrafficLightDetection()
        {
            while (true)
            {
                try{
                    //ge_server::ByteResponse result(client_->call("gettrafficlightdetection").as<ge_server::ByteResponse>());
                    auto result = vClient_[7]->call("add8", 3,4).as<int>();
                }
                catch (const std::future_error& e)
                {
                    std::cout << "add8 catch error code:" << e.code() << "\nMessage: " << e.what()<< std::endl;
                }
                catch (...)
                {
                    std::cout << "ProcTrafficLightDetection all" << std::endl;
                }
                // if (result.byte_data_uint8.empty())
                // {
                //     // std::cout << "ProcTrafficLightDetection: data is null" << std::endl;
                //     if (g_sleep)
                //     {
                //         std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime_ms));
                //     }
                //     continue;
                // }
                // // std::cout << "ProcTrafficLightDetection > " <<  result.byte_data_uint8.size() << std::endl;
                // std::string pb_str(result.byte_data_uint8.begin(), result.byte_data_uint8.end());
                // PublishTrafficLightDetection(pb_str.c_str(), pb_str.size());
            }
        }

        void Run()
        {
            std::cout << "begin listen ......." << std::endl;
            std::thread t_localizaiton(&Cyber_ge_adapter::ProcLocalization, this);
            // std::thread t_PlanningMessage(&Cyber_ge_adapter::ProcPlanningMessage, this);
            // std::thread t_PerceptionObstacles(&Cyber_ge_adapter::ProcPerceptionObstacles, this);
            // std::thread t_PerceptionObstacles_gt(&Cyber_ge_adapter::ProcPerceptionObstacles_gt, this);
            // std::thread t_Lidar(&Cyber_ge_adapter::PorcLidar, this);
            // std::thread t_Camera(&Cyber_ge_adapter::PorcCamera, this);
            // std::thread t_TF(&Cyber_ge_adapter::ProcTF, this);
            // std::thread t_TrafficLightDetection(&Cyber_ge_adapter::ProcTrafficLightDetection, this);
            t_localizaiton.join();
            // t_PlanningMessage.join();
            // t_PerceptionObstacles.join();
            // t_PerceptionObstacles_gt.join();
            // t_Lidar.join();
            // t_Camera.join();
            // t_TF.join();
            // t_TrafficLightDetection.join();
        }
    private:
        std::shared_ptr<rpc::client> client_ = nullptr;
        std::vector< std::shared_ptr<rpc::client> > vClient_;
};


int main() {

    Cyber_ge_adapter adapter("localhost", 8765);
  
    adapter.Run();
   
    std::cout << "end" << std::endl;
    return 0;
}
