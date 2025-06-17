#include <iostream>

class Log {
public:
	enum Level {
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel = LevelInfo; // m_LogLevel -> member variables that are private (convention)
public:
	void SetLevel(Level level) {
		m_LogLevel = level;
	}

	void Error(const char* message) {
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message) {
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message) {
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int Log_(void) {
	Log log;
	log.SetLevel(Log::LevelInfo);
	log.Warn("This is a Warning!");
	log.Error("This is an Error!");
	log.Info("This is some Info!");

	return 0;
}