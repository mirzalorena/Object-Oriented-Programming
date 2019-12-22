#include "userView.h"

userView::userView(QAbstractItemModel * model, QWidget * parent)
	:QWidget(parent), model{model}
{
	ui.setupUi(this);
	this->ui.userList->setModel(this->model);
}

userView::userView()
{
}
