#include "mainwindow.hpp"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    m_widget(*(new Ui::MainWindow))
{
	m_widget.setupUi(this);
	
	m_imemory.resize(IMEMORY_SIZE);
	m_dmemory.resize(DMEMORY_SIZE);
	
	m_imemoryModel.reset(new MemoryModel(m_imemory.data(), m_imemory.size()));
	m_dmemoryModel.reset(new MemoryModel(m_dmemory.data(), m_dmemory.size()));
	
	m_widget.imemoryTable->setModel(m_imemoryModel.get());
	m_widget.dmemoryTable->setModel(m_dmemoryModel.get());
	
	stack_cpu_init(&m_cpu, m_imemory.data(), m_dmemory.data());
}

MainWindow::~MainWindow()
{
}

void
MainWindow::on_actionStep_triggered()
{
	stack_cpu_step(&m_cpu);
}
