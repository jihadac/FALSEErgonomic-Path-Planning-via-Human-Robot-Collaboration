/********************************************************************************
** Form generated from reading UI file 'frames.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMES_H
#define UI_FRAMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FramesWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_parent;
    QLineEdit *parent;
    QLabel *label_child;
    QLineEdit *child;

    void setupUi(QWidget *FramesWidget)
    {
        if (FramesWidget->objectName().isEmpty())
            FramesWidget->setObjectName(QStringLiteral("FramesWidget"));
        FramesWidget->resize(514, 39);
        horizontalLayout = new QHBoxLayout(FramesWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 6, -1, 6);
        label_parent = new QLabel(FramesWidget);
        label_parent->setObjectName(QStringLiteral("label_parent"));

        horizontalLayout->addWidget(label_parent);

        parent = new QLineEdit(FramesWidget);
        parent->setObjectName(QStringLiteral("parent"));

        horizontalLayout->addWidget(parent);

        label_child = new QLabel(FramesWidget);
        label_child->setObjectName(QStringLiteral("label_child"));

        horizontalLayout->addWidget(label_child);

        child = new QLineEdit(FramesWidget);
        child->setObjectName(QStringLiteral("child"));

        horizontalLayout->addWidget(child);


        retranslateUi(FramesWidget);

        QMetaObject::connectSlotsByName(FramesWidget);
    } // setupUi

    void retranslateUi(QWidget *FramesWidget)
    {
        FramesWidget->setWindowTitle(QApplication::translate("FramesWidget", "frame names", Q_NULLPTR));
        label_parent->setText(QApplication::translate("FramesWidget", "parent:", Q_NULLPTR));
        parent->setPlaceholderText(QApplication::translate("FramesWidget", "parent frame", Q_NULLPTR));
        label_child->setText(QApplication::translate("FramesWidget", "child:", Q_NULLPTR));
        child->setPlaceholderText(QApplication::translate("FramesWidget", "child frame", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FramesWidget: public Ui_FramesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMES_H
