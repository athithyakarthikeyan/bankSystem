#include <iostream>
#include "BankAccount.h"
#include <wx/wx.h>

class BankFrame : public wxFrame {
public:
    BankFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    BankAccount account;

    wxStaticText* nameLabel;
    wxStaticText* accountNumberLabel;
    wxStaticText* balanceLabel;
    wxTextCtrl* depositCtrl;
    wxTextCtrl* withdrawCtrl;
    wxButton* depositButton;
    wxButton* withdrawButton;

    void OnDeposit(wxCommandEvent& event);
    void OnWithdraw(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_DEPOSIT = 1,
    ID_WITHDRAW
};

wxBEGIN_EVENT_TABLE(BankFrame, wxFrame)
    EVT_BUTTON(ID_DEPOSIT, BankFrame::OnDeposit)
    EVT_BUTTON(ID_WITHDRAW, BankFrame::OnWithdraw)
wxEND_EVENT_TABLE()

BankFrame::BankFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    nameLabel = new wxStaticText(this, wxID_ANY, wxT("Name: RandomName"));
    accountNumberLabel = new wxStaticText(this, wxID_ANY, wxT("Account Number: 12345"));
    balanceLabel = new wxStaticText(this, wxID_ANY, wxT("Balance: $5000.00"));

    depositCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    withdrawCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

    depositButton = new wxButton(this, ID_DEPOSIT, wxT("Deposit"));
    withdrawButton = new wxButton(this, ID_WITHDRAW, wxT("Withdraw"));

    wxBoxSizer* vBox = new wxBoxSizer(wxVERTICAL);
    vBox->Add(nameLabel, 0, wxALL, 5);
    vBox->Add(accountNumberLabel, 0, wxALL, 5);
    vBox->Add(balanceLabel, 0, wxALL, 5);
    vBox->Add(depositCtrl, 0, wxALL, 5);
    vBox->Add(withdrawCtrl, 0, wxALL, 5);
    vBox->Add(depositButton, 0, wxALL, 5);
    vBox->Add(withdrawButton, 0, wxALL, 5);

    SetSizer(vBox);
    Layout();
}

void BankFrame::OnDeposit(wxCommandEvent& event)
{
    wxString value = depositCtrl->GetValue();
    float amount;
    value.ToDouble(&amount);
    account.deposit(amount);

    balanceLabel->SetLabelText(wxString::Format(wxT("Balance: $%.2f"), account.getBalance()));
}

void BankFrame::OnWithdraw(wxCommandEvent& event)
{
    wxString value = withdrawCtrl->GetValue();
    float amount;
    value.ToDouble(&amount);
    if (account.withdraw(amount)
