#pragma once

#include "Serializable.h"
#include "../../Enums/KeyCode.h"

class KeySettings : public Serializable {
private:
    KeyCode quitButton;
    KeyCode backButton;
    KeyCode nextButton;
    KeyCode previousButton;
    KeyCode confirmButton;
    KeyCode cancelButton;
    KeyCode editButton;

public:
    KeySettings();

    int getQuitButton();

    int getBackButton();

    int getNextButton();

    int getPreviousButton();

    int getConfirmButton();

    int getCancelButton();

    int getEditButton();

    void setQuitButton(KeyCode key);

    void setBackButton(KeyCode key);

    void setNextButton(KeyCode key);

    void setPreviousButton(KeyCode key);

    void setConfirmButton(KeyCode key);

    void setCancelButton(KeyCode key);

    void setEditButton(KeyCode key);

    void getDataFromObject(std::ostream &os) const override;

    void setDataToObject(std::istream &is) override;
};
