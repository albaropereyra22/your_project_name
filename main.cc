#include <drogon/drogon.h>
using namespace drogon;

int main() {
    drogon::HttpAppFramework::instance().enableSession(1200);
    drogon::HttpAppFramework::instance()
        .registerHandler("/subscribe?newsletter1={email}",
            [](const HttpRequestPtr& req,
                std::function<void(const HttpResponsePtr&)>&& callback,
                const std::string& email)
            {
                Json::Value json;
                json["result"] = "ok";
                json["message"] = std::string("Here is the email address:") + email;
                auto resp = HttpResponse::newHttpJsonResponse(json);
                callback(resp);
            });
    drogon::HttpAppFramework::instance()
        .registerHandler("/test2?username={name}",
            [](const HttpRequestPtr& req,
                std::function<void(const HttpResponsePtr&)>&& callback,
                const std::string& name)
            {
                Json::Value json;
                json["result"] = "ok";
                json["message"] = std::string("hello,") + name;
                auto resp = HttpResponse::newHttpJsonResponse(json);
                callback(resp);
            });
    drogon::HttpAppFramework::instance()
        .registerHandler("/list_para",
            [=](const HttpRequestPtr& req,
                std::function<void(const HttpResponsePtr&)>&& callback)
            {
                auto para = req->getParameters();
                HttpViewData data;
                data.insert("title", "ListParameters");
                data.insert("parameters", para);
                auto resp = HttpResponse::newHttpViewResponse("ListParameters.csp", data);
                callback(resp);
            });
    drogon::HttpAppFramework::instance()
        .registerHandler("/slow",
            [=](const HttpRequestPtr& req,
                std::function<void(const HttpResponsePtr&)>&& callback)
            {
                Json::Value json;
                json["result"] = "ok";
                auto resp = HttpResponse::newHttpJsonResponse(json);
                callback(resp);
            },
            { Get,"TimeFilter" });
      
    // This is how you add headers to Drogon:
    // CORS Policy - Allow connections from anywhere
    app().registerPostHandlingAdvice([](const HttpRequestPtr &req, const HttpResponsePtr &resp) {
        resp->addHeader("Access-Control-Allow-Origin", "*");
    });
    //start app
    //Catch SIGINT
    app().setIntSignalHandler([&] {std::cerr << "Alarm! SIGINT!"; app().quit(); })
         //Load config file
         .loadConfigFile("C:\\Users\\dell\\your_project_name\\config.json")
         // removed because it prevents debugging 
         // select log path and log level
         //.setLogPath("C:\\Users\\dell\\your_project_name\\")
         //.setLogLevel(trantor::Logger::kWarn)
         //Run HTTP framework,the method will block in the internal event loop
         .run();
    return 0;
}
