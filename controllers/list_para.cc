#include "list_para.h"

void list_para::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
     auto para=req->getParameters();
     HttpViewData data;
     data.insert("title","ListParameters");
     data.insert("parameters",para);
     auto resp=HttpResponse::newHttpViewResponse("ListParameters.csp",data);
     callback(resp);
}
