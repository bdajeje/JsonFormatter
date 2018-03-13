#include "main_window.hpp"

#include <assert.h>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <utils/json.hpp>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	auto central_widget = new QWidget(this);
	auto main_layout    = new QVBoxLayout;
	auto btns_layout    = new QHBoxLayout;

	_error_text = new QLabel;
	_json_area  = new QTextEdit;
	_format_btn = new QPushButton("Format");
	_indentation_level = new QSpinBox;

	_indentation_level->setValue(2);
	_indentation_level->setMinimum(1);
	_indentation_level->setMaximum(16);
	_indentation_level->setPrefix("Indent: ");

	_error_text->hide();
	_error_text->setStyleSheet("QLabel { background-color : red; color : white; }");

	btns_layout->addWidget(_indentation_level);
	btns_layout->addWidget(_format_btn);

	main_layout->addWidget(_error_text);
	main_layout->addWidget(_json_area);
	main_layout->addLayout(btns_layout);
	central_widget->setLayout(main_layout);
	setCentralWidget(central_widget);

	connect(_json_area, SIGNAL(textChanged()), this, SLOT(toggleFormatBtn()));
	connect(_format_btn, SIGNAL(pressed()), this, SLOT(jsonFormat()));
	connect(_indentation_level, SIGNAL(valueChanged(int)), this, SLOT(jsonFormat()));

	toggleFormatBtn();
}

MainWindow::~MainWindow()
{

}

void MainWindow::toggleFormatBtn()
{
	_format_btn->setEnabled(!_json_area->toPlainText().isEmpty());
}

void MainWindow::jsonFormat()
{
	auto text = _json_area->toPlainText();
	if(text.isEmpty())
		return;

	try
	{
		auto result = json::parse(text.toStdString());
		_json_area->setPlainText(QString(result.dump(_indentation_level->value()).c_str()));
		_error_text->hide();
	}
	catch(...)
	{
		showError("Can't parse text");
	}
}

void MainWindow::showError(QString msg)
{
	if(msg.isEmpty())
	{
		assert(false);
		return;
	}

	_error_text->setText(msg);
	_error_text->show();
}
