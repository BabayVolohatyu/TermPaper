#pragma once
#include "Serializable.h"
#include "../../UI/Headers/Visual.h"

class Tag : public Serializable, public Visual {
    private:
    std::string tagName;

    public:
    Tag() = delete;

    Tag(const std::string& tagName = "New Tag", Color color = Color::LIGHT_RED);

    ~Tag() override = default;

    [[nodiscard]] std::string getTagName() const;

    void setTagName(const std::string& tagName);

    void print() override;

    bool operator==(const Tag &other) const;

    bool operator!=(const Tag &other) const;

    bool operator<=(const Tag &other) const = delete;

    bool operator>=(const Tag &other) const = delete;

    bool operator<(const Tag &other) const = delete;

    bool operator>(const Tag &other) const = delete;

    void getDataFromObject(std::ostream& os) const override;

    void setDataToObject(std::istream& is) override;
};
