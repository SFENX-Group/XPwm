#ifndef PASSWORDCHANGER_HPP
#define PASSWORDCHANGER_HPP

#include <QDialog>

#include "../design/ui_PasswordChangerDialog.h"

namespace Ui {
class PasswordChangerDialog;
}

class PasswordChangerDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(PasswordChangerDialog)

  public:
    explicit PasswordChangerDialog(QWidget *parent = nullptr);
    ~PasswordChangerDialog() override;
    [[nodiscard]] const bool PasswordEnteredCorrectly() const { return !this->m_ui->newPasswordLE1->text().isEmpty() && !this->m_ui->newPasswordLE1->text().isNull() && this->m_ui->newPasswordLE1->text() == this->m_ui->newPasswordLE2->text(); }
    [[nodiscard]] inline const QString GetNewPassword() const { return this->m_ui->newPasswordLE1->text(); }
    [[nodiscard]] inline const QString GetCurrentPassword() const { return this->m_ui->currentPasswordLE->text(); }

  private slots:
    void sl_ShowPasswordCheckStateChanged(int state);
    void sl_GeneratePasswordTBClicked(bool checked);
    void sl_CopyClicked(bool checked);

  private:
    Ui::PasswordChangerDialog *m_ui;
};

#endif  // PASSWORDCHANGER_HPP
