#ifndef QCAN_SERVER_DIALOG_HPP_
#define QCAN_SERVER_DIALOG_HPP_


#include <QAction>
#include <QDialog>
#include <QMenu>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QToolBox>

#include "ui_ServerConfig.h"
#include "qcan_server.hpp"
#include "qcan_interface_widget.hpp"

class QCanServerDialog : public QDialog
{
    Q_OBJECT

public:
    QCanServerDialog(QWidget *parent = 0);
    ~QCanServerDialog();

    QToolBox *pclTbxNetworkM;
    QCanInterfaceWidget *apclTbxQCanInterfaceWidgetM[QCAN_NETWORK_MAX];

public slots:

   void onNetworkChange(int slIndexV);
   void onNetworkConfBitrate(int slBitrateV);
   void onNetworkConfEnable(bool btEnableV);
   void onNetworkConfListenOnly(bool btEnableV);
   //void onNetworkConfInterface(QMouseEvent *);

   /*!
   ** This slot is triggered on change of the physical CAN interface.
   ** The parameter \c pclCanInterfaceV is a pointer to a new interface. If
   ** \c pclCanInterfaceV is NULL, the physical interface shall be removed.
   */
   void onInterfaceChange(uint8_t ubIdxV, QCanInterface * pclCanIfV, uint8_t ubChannelV);

   void onNetworkShowCanFrames(uint32_t ulFrameCntV);
   void onNetworkShowErrFrames(uint32_t ulFrameCntV);
   void onNetworkShowLoad(uint8_t ubLoadV, uint32_t ulMsgPerSecV);

private:
   void     createActions(void);
   void     createTrayIcon(void);
   void     setupNetworks(void);
   void     showNetworkConfiguration(void);
   void     setIcon(void);
   void     updateUI(uint8_t ubNetworkIdxV);

   Ui_ServerConfig   ui;
   QAction *         pclActionCnfgP;
   QAction *         pclActionQuitP;

   QSystemTrayIcon * pclIconTrayP;
   QMenu *           pclMenuTrayP;

   QCanServer *      pclCanServerP;
   QSettings *       pclSettingsP;

   int32_t           slLastNetworkIndexP;

};

#endif // QCAN_SERVER_DIALOG_HPP_