// hello.cc 插件程序c++
#include <node.h>
#include <iostream>

using namespace std;

namespace demo
{

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  //这句话相当于js里面的return. 相关见node文档.
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
  int haha = 500; //这块是为了调试清楚而写的代码
  haha ++;
  haha = 0;
  cout << haha << endl;
}

void init(Local<Object> exports)
{
  NODE_SET_METHOD(exports, "hello", Method);
}

NODE_MODULE(addon, init)

} // namespace demo