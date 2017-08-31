#include "Engine.h"
#include "Keyboard.h"
#include "Pyramid.h"
using namespace std;

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Initialize(const char* windowTitle){

	if (!glfwInit()){
		cout << "Error initializing GLFW" << endl;
		return false;
    }
    
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle , NULL, NULL);
	if (window == NULL){
        cout << "Error creating window" << endl;
		return false;
	}
    
	if (!window){
        glfwTerminate();
        return -1;
    }

	//GLFW Setup
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	
	//Enable vsync
    glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	glfwSetKeyCallback(window, Keyboard::KeyCallback);
	//glfwSetKeyCallback(window, Keyboard::key_callback);
    	
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);
	
    //Get GL version info
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);  
    cout << "\nRenderer.." << "\t" << renderer;
	cout << "\nOpenGL version supported.." << "\t" << version << endl;
	
	//GL Setup
	glViewport(0, 0, -50, 10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, -60, 0, 30, -30, 10);
	glDepthRange(-60, 10);
    glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
    glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
	return true;
}

void Engine::Update(){
    cout << "In Update.." << endl;
	glfwPollEvents();
}

/* void Engine::Input(){
	cout << "In Input.." << endl;
	if(Keyboard::KeyDown(GLFW_KEY_ESCAPE)){
		glfwSetWindowShouldClose(window, GL_TRUE);		
	}
} */

void Engine::BeginRender(){
	cout << "In BeginRender.." << endl;
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    Draw::drawPyramid();
}

void Engine::EndRender(){
    cout << "In EndRender.." << endl;
	glfwSwapBuffers(window);
	//glfwTerminate();
}