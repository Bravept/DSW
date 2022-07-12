// Copyright (c) 2011-2013 The Bitcoin developers
// Copyright (c) 2017-2019 The PIVX developers
// Copyright (c) 2021-2022 The DECENOMY Core Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ASKPASSPHRASEDIALOG_H
#define BITCOIN_QT_ASKPASSPHRASEDIALOG_H

#include <QDialog>
#include "qt/pivx/prunnable.h"
#include "allocators.h"
#include <QCheckBox>

class WalletModel;
class PIVXGUI;
class CWallet;

namespace Ui
{
class AskPassphraseDialog;
class QCheckBox;
}

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskPassphraseDialog : public QDialog, public Runnable
{
    Q_OBJECT

public:
    enum class Mode {
        Encrypt,         /**< Ask passphrase twice and encrypt */
        UnlockAnonymize, /**< Ask passphrase and unlock only for anonymization */
        Unlock,          /**< Ask passphrase and unlock */
        AddOTP,          /**< Ask to generate 2fa seed */
        ChangePass,      /**< Ask old passphrase + new passphrase twice */
        Decrypt          /**< Ask passphrase and decrypt wallet */
    };

    // Context from where / for what the passphrase dialog was called to set the status of the checkbox
    // Partly redundant to Mode above, but offers more flexibility for future enhancements
    enum class Context {
        Unlock_Menu,    /** Unlock wallet from menu     */
        Unlock_Full,    /** Wallet needs to be fully unlocked */
        Encrypt,        /** Encrypt unencrypted wallet */
        AddOTP,          /**< Ask to generate 2fa seed */
        ToggleLock,     /** Toggle wallet lock state */
        ChangePass,     /** Change passphrase */
        Send_PIV,       /** Send __DSW__ */
        BIP_38,         /** BIP38 menu */
        Multi_Sig,      /** Multi-Signature dialog */
        Sign_Message,   /** Sign/verify message dialog */
        UI_Vote,        /** Governance Tab UI Voting */
    };

    explicit AskPassphraseDialog(Mode mode, QWidget* parent, WalletModel* model, Context context);
    ~AskPassphraseDialog();

    void showEvent(QShowEvent *event) override;
    void accept() override;

private:
    Ui::AskPassphraseDialog* ui;
    Mode mode;
    WalletModel* model;
    Context context;
    bool fCapsLock;
    SecureString newpassCache = "";

    void updateWarningsLabel();
    void run(int type) override;
    void onError(QString error, int type) override;
    QCheckBox *btnWatch;

    void initWatch(QWidget *parent);

private Q_SLOTS:
    void onWatchClicked();
    void onGenerateSeedClicked();
    void generateSeed();
    void textChanged();
    void warningMessage();
    void errorEncryptingWallet();
    bool openStandardDialog(QString title = "", QString body = "", QString okBtn = "OK", QString cancelBtn = "");
    bool openOtpDialog(QString title, QString body, QString okBtn, QString cancelBtn, QString qrOtp);

protected:
    bool event(QEvent* event) override ;
    bool eventFilter(QObject* object, QEvent* event) override;
};

#endif // BITCOIN_QT_ASKPASSPHRASEDIALOG_H
