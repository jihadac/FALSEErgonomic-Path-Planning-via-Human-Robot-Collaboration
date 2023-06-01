/********************************************************************************
** Form generated from reading UI file 'euler.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EULER_H
#define UI_EULER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EulerWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QComboBox *a1;
    QDoubleSpinBox *e1;
    QComboBox *a2;
    QDoubleSpinBox *e2;
    QComboBox *a3;
    QDoubleSpinBox *e3;

    void setupUi(QWidget *EulerWidget)
    {
        if (EulerWidget->objectName().isEmpty())
            EulerWidget->setObjectName(QStringLiteral("EulerWidget"));
        EulerWidget->resize(345, 27);
        horizontalLayout = new QHBoxLayout(EulerWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        a1 = new QComboBox(EulerWidget);
        a1->setObjectName(QStringLiteral("a1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(a1->sizePolicy().hasHeightForWidth());
        a1->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(a1);

        e1 = new QDoubleSpinBox(EulerWidget);
        e1->setObjectName(QStringLiteral("e1"));
        e1->setDecimals(1);
        e1->setMinimum(-360);
        e1->setMaximum(360);

        horizontalLayout->addWidget(e1);

        a2 = new QComboBox(EulerWidget);
        a2->setObjectName(QStringLiteral("a2"));
        sizePolicy.setHeightForWidth(a2->sizePolicy().hasHeightForWidth());
        a2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(a2);

        e2 = new QDoubleSpinBox(EulerWidget);
        e2->setObjectName(QStringLiteral("e2"));
        e2->setDecimals(1);
        e2->setMinimum(-360);
        e2->setMaximum(360);

        horizontalLayout->addWidget(e2);

        a3 = new QComboBox(EulerWidget);
        a3->setObjectName(QStringLiteral("a3"));
        sizePolicy.setHeightForWidth(a3->sizePolicy().hasHeightForWidth());
        a3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(a3);

        e3 = new QDoubleSpinBox(EulerWidget);
        e3->setObjectName(QStringLiteral("e3"));
        e3->setDecimals(1);
        e3->setMinimum(-360);
        e3->setMaximum(360);

        horizontalLayout->addWidget(e3);

        QWidget::setTabOrder(a1, a2);
        QWidget::setTabOrder(a2, a3);
        QWidget::setTabOrder(a3, e1);
        QWidget::setTabOrder(e1, e2);
        QWidget::setTabOrder(e2, e3);

        retranslateUi(EulerWidget);

        QMetaObject::connectSlotsByName(EulerWidget);
    } // setupUi

    void retranslateUi(QWidget *EulerWidget)
    {
        EulerWidget->setWindowTitle(QApplication::translate("EulerWidget", "Form", Q_NULLPTR));
        a1->clear();
        a1->insertItems(0, QStringList()
         << QApplication::translate("EulerWidget", "x", Q_NULLPTR)
         << QApplication::translate("EulerWidget", "y", Q_NULLPTR)
         << QApplication::translate("EulerWidget", "z", Q_NULLPTR)
        );
        a2->clear();
        a2->insertItems(0, QStringList()
         << QApplication::translate("EulerWidget", "x", Q_NULLPTR)
         << QApplication::translate("EulerWidget", "y", Q_NULLPTR)
         << QApplication::translate("EulerWidget", "z", Q_NULLPTR)
        );
        a3->clear();
        a3->insertItems(0, QStringList()
         << QApplication::translate("EulerWidget", "x", Q_NULLPTR)
         << QApplication::translate("EulerWidget", "y", Q_NULLPTR)
         << QApplication::translate("EulerWidget", "z", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class EulerWidget: public Ui_EulerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EULER_H
