#pragma once
#include <string>
#include <vector>

using namespace std;

class FWorld;
//class AActor;

//추상 클래스
class Engine
{
public:
	Engine();
	virtual ~Engine();

	virtual void BeginPlay();

	virtual void EndPlay();

	//순수 가상 함수
	virtual void Initialize() = 0;
	virtual void Terminalize() = 0;

	void Run();
	void QuitGame();


	inline static int GetKeyCode()
	{
		return KeyCode;
	}

	vector<class AActor*>& GetAllActors();


protected:

	virtual void Input();
	virtual void Tick();
	virtual void Render();

	void Load(string MapFilename);

	void SortActor();

	FWorld* MyWorld;

	static int KeyCode;

	bool bIsRunning = true;
};