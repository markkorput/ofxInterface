//
#include "ofxUnitTests.h"
#include "ofxInterface.h"

// macros to isolate tests within their own local scope
#define TEST_START(x) {ofLog()<<"CASE: "<<#x;
#define TEST_END }

class ofApp: public ofxUnitTestsApp{

    void run(){

    }
};


#include "ofAppNoWindow.h"
#include "ofAppRunner.h"

int main( ){
  ofInit();
  auto window = std::make_shared<ofAppNoWindow>();
  auto app = std::make_shared<ofApp>();
  ofRunApp(window, app);
  return ofRunMainLoop();
}
