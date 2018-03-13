#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>

class MainWindow final : public QMainWindow
{
	Q_OBJECT

	public:

		MainWindow(QWidget *parent = 0);
		~MainWindow();

	public slots:

		void jsonFormat();
		void showError(QString msg);
		void toggleFormatBtn();

	protected:

		QLabel* _error_text;
		QTextEdit* _json_area;
		QPushButton* _format_btn;
		QSpinBox* _indentation_level;
};

#endif // MAIN_WINDOW_HPP
