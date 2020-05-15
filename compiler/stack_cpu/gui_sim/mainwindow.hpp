#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <memory>
#include <vector>

#include "memorymodel.hpp"
#include "stack_cpu.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	
	explicit MainWindow(QWidget* = nullptr);
	
	~MainWindow();
	
private slots:
	
	void on_actionStep_triggered();
	    
private:
	
	Q_DISABLE_COPY(MainWindow)
	    
	Ui::MainWindow& m_widget;
	
	std::vector<uint8_t> m_imemory;
	
	std::vector<uint8_t> m_dmemory;
	
	std::unique_ptr<MemoryModel> m_imemoryModel;
	
	std::unique_ptr<MemoryModel> m_dmemoryModel;
	
	stack_cpu_t m_cpu;
};

#endif /* MAINWINDOW_HPP */
