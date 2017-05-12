//
#include "ofxUnitTests.h"
#include "ofxInterface.h"

#include <functional>

// macros to isolate tests within their own local scope
#define TEST_START(x) {ofLog()<<"CASE: "<<#x;
#define TEST_END }

class CustomNode : public ofxInterface::Node {
public:
    typedef std::function<void()> DestructorFunc;

    DestructorFunc destructorFunc;

    CustomNode(){
        this->destructorFunc = [](){
            // does nothing by default
        };
    }

    ~CustomNode(){
        this->destructorFunc();
    }
};

class ofApp: public ofxUnitTestsApp{
    void run(){
        TEST_START(delete children on remove)
            CustomNode *rootNode, *childA, *childB;
            rootNode = new CustomNode();
            childA = new CustomNode();
            childB = new CustomNode();

            vector<string> result;
            rootNode->destructorFunc = [&result](){
                result.push_back("Destruct-Root");
            };

            childA->destructorFunc = [&result](){
                result.push_back("Destruct-A");
            };

            childB->destructorFunc = [&result](){
                result.push_back("Destruct-B");
            };

            rootNode->addChild(childA);
            rootNode->addChild(childB);
            delete rootNode;

            test_eq(ofJoinString(result, " -> "), "Destruct-Root -> Destruct-A -> Destruct-B", "");
        TEST_END
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
