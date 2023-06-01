/********************************************************************************
** Form generated from reading UI file 'transform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORM_H
#define UI_TRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "EulerWidget.h"

QT_BEGIN_NAMESPACE

class Ui_TransformWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *posGroup;
    QHBoxLayout *horizontalLayout;
    QLabel *pos_label_x;
    QDoubleSpinBox *pos_x;
    QSpacerItem *pos_spacer_xy;
    QLabel *pos_label_y;
    QDoubleSpinBox *pos_y;
    QSpacerItem *pos_spacer_yz;
    QLabel *pos_label_z;
    QDoubleSpinBox *pos_z;
    QGroupBox *rotGroup;
    QVBoxLayout *verticalLayout;
    EulerWidget *euler_widget_;
    QSpacerItem *bottom_spacer;

    void setupUi(QWidget *TransformWidget)
    {
        if (TransformWidget->objectName().isEmpty())
            TransformWidget->setObjectName(QStringLiteral("TransformWidget"));
        TransformWidget->resize(418, 153);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransformWidget->sizePolicy().hasHeightForWidth());
        TransformWidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(TransformWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        posGroup = new QGroupBox(TransformWidget);
        posGroup->setObjectName(QStringLiteral("posGroup"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(posGroup->sizePolicy().hasHeightForWidth());
        posGroup->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(posGroup);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 6, -1, 0);
        pos_label_x = new QLabel(posGroup);
        pos_label_x->setObjectName(QStringLiteral("pos_label_x"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pos_label_x->sizePolicy().hasHeightForWidth());
        pos_label_x->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pos_label_x);

        pos_x = new QDoubleSpinBox(posGroup);
        pos_x->setObjectName(QStringLiteral("pos_x"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pos_x->sizePolicy().hasHeightForWidth());
        pos_x->setSizePolicy(sizePolicy3);
        pos_x->setDecimals(1);
        pos_x->setMinimum(-1e+9);
        pos_x->setMaximum(1e+9);

        horizontalLayout->addWidget(pos_x);

        pos_spacer_xy = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(pos_spacer_xy);

        pos_label_y = new QLabel(posGroup);
        pos_label_y->setObjectName(QStringLiteral("pos_label_y"));
        sizePolicy2.setHeightForWidth(pos_label_y->sizePolicy().hasHeightForWidth());
        pos_label_y->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pos_label_y);

        pos_y = new QDoubleSpinBox(posGroup);
        pos_y->setObjectName(QStringLiteral("pos_y"));
        sizePolicy3.setHeightForWidth(pos_y->sizePolicy().hasHeightForWidth());
        pos_y->setSizePolicy(sizePolicy3);
        pos_y->setDecimals(1);
        pos_y->setMinimum(-1e+9);
        pos_y->setMaximum(1e+9);

        horizontalLayout->addWidget(pos_y);

        pos_spacer_yz = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(pos_spacer_yz);

        pos_label_z = new QLabel(posGroup);
        pos_label_z->setObjectName(QStringLiteral("pos_label_z"));
        sizePolicy2.setHeightForWidth(pos_label_z->sizePolicy().hasHeightForWidth());
        pos_label_z->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pos_label_z);

        pos_z = new QDoubleSpinBox(posGroup);
        pos_z->setObjectName(QStringLiteral("pos_z"));
        sizePolicy3.setHeightForWidth(pos_z->sizePolicy().hasHeightForWidth());
        pos_z->setSizePolicy(sizePolicy3);
        pos_z->setDecimals(1);
        pos_z->setMinimum(-1e+9);
        pos_z->setMaximum(1e+9);

        horizontalLayout->addWidget(pos_z);


        verticalLayout_2->addWidget(posGroup);

        rotGroup = new QGroupBox(TransformWidget);
        rotGroup->setObjectName(QStringLiteral("rotGroup"));
        verticalLayout = new QVBoxLayout(rotGroup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 6, -1, 0);
        euler_widget_ = new EulerWidget(rotGroup);
        euler_widget_->setObjectName(QStringLiteral("euler_widget_"));
        sizePolicy3.setHeightForWidth(euler_widget_->sizePolicy().hasHeightForWidth());
        euler_widget_->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(euler_widget_);


        verticalLayout_2->addWidget(rotGroup);

        bottom_spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(bottom_spacer);


        retranslateUi(TransformWidget);

        QMetaObject::connectSlotsByName(TransformWidget);
    } // setupUi

    void retranslateUi(QWidget *TransformWidget)
    {
        TransformWidget->setWindowTitle(QApplication::translate("TransformWidget", "Form", Q_NULLPTR));
        posGroup->setTitle(QApplication::translate("TransformWidget", "position", Q_NULLPTR));
        pos_label_x->setText(QApplication::translate("TransformWidget", "x:", Q_NULLPTR));
        pos_label_y->setText(QApplication::translate("TransformWidget", "y:", Q_NULLPTR));
        pos_label_z->setText(QApplication::translate("TransformWidget", "z:", Q_NULLPTR));
        rotGroup->setTitle(QApplication::translate("TransformWidget", "Euler angles", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TransformWidget: public Ui_TransformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
