#include "ListModel.h"
#include "MyDeligate.h"
#include <QtWidgets/QApplication>
#include <QListView>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	ListModel* model = new ListModel;
	QListView* view = new QListView;
	view->setModel(model);
	MyDeligate* delegate = new MyDeligate;
	view->setItemDelegate(delegate);
	

	view->resize(700, 350);
	view->show();
	return app.exec();
}
