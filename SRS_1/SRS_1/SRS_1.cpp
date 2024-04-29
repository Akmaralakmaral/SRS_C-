#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Базовый класс User
class User {
protected:
    string name;
    string role;

public:
    User(const string& n, const string& r) : name(n), role(r) {}

    virtual void performTask() const = 0;

    const string& getName() const {
        return name;
    }

    const string& getRole() const {
        return role;
    }
};

// Класс Работник автосервиса
class ServiceWorker : public User {
public:
    ServiceWorker(const string& n) : User(n, "Работник автосервиса") {}

    void performTask() const override {
        cout << "Выполняю задачу в автосервисе..." << endl;
    }
};

// Класс Работник магазина запчастей
class PartsStoreEmployee : public User {
public:
    PartsStoreEmployee(const string& n) : User(n, "Работник магазина запчастей") {}

    void performTask() const override {
        cout << "Помогаю клиенту в магазине запчастей..." << endl;
    }
};

// Класс Поставщик-оптовик
class WholesaleSupplier : public User {
public:
    WholesaleSupplier(const string& n) : User(n, "Поставщик-оптовик") {}

    void performTask() const override {
        cout << "Поставляю запчасти оптом..." << endl;
    }
};


// Класс Деталь
class Part
{
private:
    string name;
    string creationDate;
    vector<string> alternativeNames;

public:
    Part(const string& n, const string& date) : name(n), creationDate(date) {}

    const string& getName() const
    {
        return name;
    }

    const string& getCreationDate() const
    {
        return creationDate;
    }

    // Добавление взаимозаменяемой детали по имени
    void addAlternative(const string& altPartName)
    {
        // Проверяем, что такой детали еще нет в списке
        if (find(alternativeNames.begin(), alternativeNames.end(), altPartName) == alternativeNames.end())
        {
            alternativeNames.push_back(altPartName);
            cout << "Альтернативная деталь '" << altPartName << "' добавлена для '" << name << "'." << endl;
        }
        else
        {
            cout << "Ошибка: Деталь '" << altPartName << "' уже является альтернативой для '" << name << "'." << endl;
        }
    }

    // Замена выбранной детали на одну из альтернативных деталей
    bool replaceWithAlternative(const string& altPartName)
    {
        // Проверяем, что альтернативная деталь существует в списке альтернатив
        auto it = find(alternativeNames.begin(), alternativeNames.end(), altPartName);
        if (it != alternativeNames.end())
        {
            // Заменяем текущую деталь на выбранную альтернативу
            name = altPartName;
            return true;
        }
        else
        {
            cout << "Ошибка: Деталь '" << altPartName << "' не является альтернативой для '" << name << "'." << endl;
            return false;
        }
    }

    // Удаление взаимозаменяемой детали по имени
    void removeAlternative(const string& altPartName)
    {
        auto it = find(alternativeNames.begin(), alternativeNames.end(), altPartName);
        if (it != alternativeNames.end())
        {
            alternativeNames.erase(it);
            cout << "Альтернативная деталь '" << altPartName << "' удалена для '" << name << "'." << endl;
        }
        else
        {
            cout << "Ошибка: Деталь '" << altPartName << "' не является альтернативой для '" << name << "'." << endl;
        }
    }

    // Вывод списка взаимозаменяемых деталей
    void printAlternatives() const
    {
        cout << "Альтернативные детали для '" << name << "':" << endl;
        for (const auto& altName : alternativeNames)
        {
            cout << "- " << altName << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const Part& part)
    {
        os << "Деталь: " << part.getName() << endl;
        os << "Дата создания: " << part.getCreationDate() << endl;
        return os;
    }
};


// Класс Узел
class Component
{
private:
    string name;
    vector<pair<Part, int>> partsRequired;
    string creationDate;

public:
    Component(const string& n, const string& date) : name(n), creationDate(date) {}

    void addPart(const Part& part, int quantity)
    {
        partsRequired.push_back(make_pair(part, quantity));
    }

    const string& getName() const
    {
        return name;
    }

    const string& getCreationDate() const
    {
        return creationDate;
    }

    const vector<pair<Part, int>>& getRequiredParts() const
    {
        return partsRequired;
    }


    friend ostream& operator<<(ostream& os, const Component& component)
    {
        os << "Узел: " << component.getName() << endl;
        os << "Дата создания: " << component.getCreationDate() << endl;
        os << "Требуемые детали:" << endl;
        for (const auto& pair : component.partsRequired)
        {
            os << " - " << pair.first.getName() << " (количество: " << pair.second << ")" << endl;
        }
        return os;
    }
};


// Класс Агрегат
class Assembly
{
private:
    string name;
    vector<pair<Component, int>> componentsRequired;
    string creationDate;  // Дата создания агрегата

public:
    Assembly(const string& n, const string& date) : name(n), creationDate(date) {}

    void addComponent(const Component& component, int quantity)
    {
        componentsRequired.push_back(make_pair(component, quantity));
    }

    const string& getName() const
    {
        return name;
    }

    const string& getCreationDate() const
    {
        return creationDate;
    }

    const vector<pair<Component, int>>& getRequiredComponents() const
    {
        return componentsRequired;
    }

    friend ostream& operator<<(ostream& os, const Assembly& assembly)
    {
        os << "Агрегат: " << assembly.getName() << endl;
        os << "Дата создания: " << assembly.getCreationDate() << endl;
        os << "Требуемые компоненты:" << endl;
        for (const auto& pair : assembly.componentsRequired)
        {
            os << " - " << pair.first.getName() << " (количество: " << pair.second << ")" << endl;
        }
        return os;
    }
};


// Класс Страна
class Country
{
private:
    string name;

public:
    Country(const string& n) : name(n) {}

    const string& getName() const
    {
        return name;
    }

    friend ostream& operator<<(ostream& os, const Country& country)
    {
        os << "Страна: " << country.getName() << endl;
        return os;
    }
};


// Класс Фирма-изготовитель
class Manufacturer
{
private:
        string name;
        Country country;
        string creationDate;

public:
    Manufacturer(const string& n, const Country& c, const string& date) : name(n), country(c), creationDate(date) {}

    const string& getName() const
    {
        return name;
    }

    const Country& getCountry() const
    {
        return country;
    }

    const string& getCreationDate() const
    {
        return creationDate;
    }

    friend ostream& operator<<(ostream& os, const Manufacturer& manufacturer)
    {
        os << "Фирма-изготовитель: " << manufacturer.getName() << endl;
        os << "Страна: " << manufacturer.getCountry().getName() << endl;
        os << "Дата создания: " << manufacturer.getCreationDate() << endl;
        return os;
    }
};

// Класс Марка автомобиля
class CarBrand
{
private:
    string name;
    Manufacturer manufacturer;
    string creationDate;
    vector<Assembly> assemblies; 

public:
    CarBrand(const string& n, const Manufacturer& m, const string& date) : name(n), manufacturer(m), creationDate(date) {}

    const string& getName() const
    {
        return name;
    }

    const Manufacturer& getManufacturer() const
    {
        return manufacturer;
    }

    const string& getCreationDate() const
    {
        return creationDate;
    }

   
    void addAssembly(const Assembly& assembly)
    {
        assemblies.push_back(assembly);
    }

    
    const vector<Assembly>& getAssemblies() const
    {
        return assemblies;
    }

    friend ostream& operator<<(ostream& os, const CarBrand& carBrand)
    {
        os << "Марка автомобиля: " << carBrand.getName() << endl;
        os << "Фирма-изготовитель: " << carBrand.getManufacturer().getName() << endl;
        os << "Дата создания: " << carBrand.getCreationDate() << endl;
        os << "Агрегаты:" << endl;
        for (const auto& assembly : carBrand.assemblies)
        {
            os << assembly << endl; // Используем перегруженный оператор << для вывода каждого агрегата
        }
        return os;
    }
};

// Функция для вывода объектов определенного типа
template<typename T>
void printObjects(const vector<T>& objects)
{
    if (objects.empty())
    {
        cout << "Нет добавленных объектов данного типа." << endl;
        return;
    }

    for (const auto& obj : objects)
    {
        cout << "----------------------" << endl;
        cout << obj; // Используем перегруженный оператор << для вывода объекта
    }
}



int main()
{
    setlocale(LC_ALL, "ru");

    vector<Country> countries;
    vector<Manufacturer> manufacturers;
    vector<CarBrand> carBrands;
    vector<Part> parts;
    vector<Component> components;
    vector<Assembly> assemblies;
    vector<User*> users;
    int choice;
    bool exitMenu = false;

    while (!exitMenu)
    {
        cout << "================ Меню ================" << endl;
        cout << "1. Добавление Страны" << endl;
        cout << "2. Добавление Фирма-изготовитель" << endl;
        cout << "3. Добавление Марка автомобиля" << endl;
        cout << "4. Добавление Деталь" << endl;
        cout << "5. Добавление Узел" << endl;
        cout << "6. Добавление Агрегат" << endl;
        cout << "7. Вывод стран" << endl;
        cout << "8. Вывод фирм-изготовителей" << endl;
        cout << "9. Вывод марок автомобилей" << endl;
        cout << "10. Вывод деталей" << endl;
        cout << "11. Вывод узлов" << endl;
        cout << "12. Вывод агрегатов" << endl;
        cout << "13. Ввод альтернативных деталей" << endl;
        cout << "14. Вывод альтернативных деталей" << endl;
        cout << "15. Замена детали на альтернативу (Взаимозаменаемоять)" << endl;
        cout << "16. Ввод работника автосервиса" << endl;
        cout << "17. Ввод работника магазина запчастей" << endl;
        cout << "18. Ввод поставщика-оптовика" << endl;
        cout << "19. Вывести информацию о сотрудниках" << endl;
        cout << "20. Выход" << endl;
        cout << "======================================" << endl;
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string countryName;
            cout << "Введите Страну: ";
            cin >> countryName;
            Country newCountry(countryName);
            countries.push_back(newCountry);
            cout << "Страна добавлен успешно." << endl;
            break;
        }
        case 2:
        {
            string manufacturerName, countryName, manufacturerCreationDate;
            int countryIndex = -1; // Инициализируем индекс страны как -1 (нет совпадений)
            cout << "Введите Фирма-изготовитель: ";
            cin >> manufacturerName;
            cout << "Введите Страну для Фирма-изготовитель: ";
            cin >> countryName;
            cout << "Введите дату создания для Фирма-изготовитель (YYYY-MM-DD): ";
            cin >> manufacturerCreationDate;

            // Поиск страны в векторе countries
            for (size_t i = 0; i < countries.size(); ++i)
            {
                if (countries[i].getName() == countryName)
                {
                    countryIndex = i;
                    break;
                }
            }

            // Если страна найдена
            if (countryIndex != -1)
            {
                Manufacturer newManufacturer(manufacturerName, countries[countryIndex], manufacturerCreationDate);
                manufacturers.push_back(newManufacturer);
                cout << "Фирма-изготовитель добавлена успешно." << endl;
            }
            else
            {
                cout << "Ошибка: Страна '" << countryName << "' не найдена." << endl;
            }
            break;
        }
        case 3:
        {
            string carBrandName, manufacturerName, carBrandCreationDate;
            int manufacturerIndex = -1; // Инициализируем индекс производителя как -1 (нет совпадений)
            cout << "Введите Марка автомобиля : ";
            cin >> carBrandName;
            cout << "Введите Фирма-изготовитель для Марка автомобиля: ";
            cin >> manufacturerName;
            cout << "Введите дату создания для Марка автомобиля (YYYY-MM-DD): ";
            cin >> carBrandCreationDate;

            // Поиск производителя в векторе manufacturers
            for (size_t i = 0; i < manufacturers.size(); ++i)
            {
                if (manufacturers[i].getName() == manufacturerName)
                {
                    manufacturerIndex = i;
                    break;
                }
            }

            // Если производитель найден
            if (manufacturerIndex != -1)
            {
                CarBrand newCarBrand(carBrandName, manufacturers[manufacturerIndex], carBrandCreationDate);
                carBrands.push_back(newCarBrand);
                cout << "Марка автомобиля добавлена успешно." << endl;
            }
            else
            {
                cout << "Ошибка: Фирма-изготовитель '" << manufacturerName << "' не найдена." << endl;
            }
            break;
        }
        case 4:
        {
            string partName, creationDate;
            cout << "Введите Деталь: ";
            cin >> partName;
            cout << "Введите дату создания для Деталь (YYYY-MM-DD): ";
            cin >> creationDate;
            Part newPart(partName, creationDate);
            parts.push_back(newPart);
            cout << "Деталь добавлен успешно." << endl;
            break;
        }
        case 5:
        {
            string componentName, creationDate;
            cout << "Введите Узел: ";
            cin >> componentName;
            cout << "Введите дату создания для Узел (YYYY-MM-DD): ";
            cin >> creationDate;
            Component newComponent(componentName, creationDate);

            // Ввод деталей и их количества
            int numParts;
            cout << "Сколько деталей нужно добавить в узел '" << componentName << "': ";
            cin >> numParts;

            bool allPartsExist = true; // Флаг, указывающий на наличие всех деталей

            for (int i = 0; i < numParts; ++i)
            {
                string partName;
                int partQuantity;
                cout << "Введите название детали " << i + 1 << ": ";
                cin >> partName;
                cout << "Введите количество детали " << partName << ": ";
                cin >> partQuantity;

                // Проверяем, существует ли такая деталь в векторе parts
                bool partFound = false;
                for (const auto& part : parts)
                {
                    if (part.getName() == partName)
                    {
                        partFound = true;
                        break;
                    }
                }

                // Если деталь не найдена, устанавливаем флаг allPartsExist в false
                if (!partFound)
                {
                    cout << "Деталь '" << partName << "' не найдена. Узел не будет создан." << endl;
                    allPartsExist = false;
                    break; // Прерываем цикл
                }

                // Создаем новую деталь
                Part newPart(partName, creationDate);

                // Добавляем деталь в узел с указанием количества
                newComponent.addPart(newPart, partQuantity);
            }

            // Если все детали найдены, добавляем созданный узел (компонент) в вектор components
            if (allPartsExist)
            {
                components.push_back(newComponent);
                cout << "Узел добавлен успешно." << endl;
            }
            break;
        }
        case 6:
        {
            string assemblyName, creationDate;
            cout << "Введите Агрегат: ";
            cin >> assemblyName;
            cout << "Введите дату создания для Агрегат (YYYY-MM-DD): ";
            cin >> creationDate;
            Assembly newAssembly(assemblyName, creationDate);

            // Ввод компонентов и их количества
            int numComponents;
            cout << "Сколько компонентов нужно добавить в агрегат '" << assemblyName << "': ";
            cin >> numComponents;

            bool allComponentsExist = true; // Флаг, указывающий на наличие всех компонентов

            for (int i = 0; i < numComponents; ++i)
            {
                string componentName;
                int componentQuantity;
                cout << "Введите название компонента " << i + 1 << ": ";
                cin >> componentName;
                cout << "Введите количество компонента " << componentName << ": ";
                cin >> componentQuantity;

                // Проверяем, существует ли такой компонент в векторе components
                bool componentFound = false;
                for (const auto& component : components)
                {
                    if (component.getName() == componentName)
                    {
                        componentFound = true;
                        break;
                    }
                }

                // Если компонент не найден, устанавливаем флаг allComponentsExist в false
                if (!componentFound)
                {
                    cout << "Компонент '" << componentName << "' не найден. Агрегат не будет создан." << endl;
                    allComponentsExist = false;
                    break; // Прерываем цикл
                }

                // Добавляем компонент в агрегат с указанием количества
                newAssembly.addComponent(components[i], componentQuantity);
            }

            // Если все компоненты найдены, добавляем созданный агрегат в вектор assemblies
            if (allComponentsExist)
            {
                assemblies.push_back(newAssembly);
                cout << "Агрегат добавлен успешно." << endl;
            }
            break;
        }
        case 7:
        {
            // Вывод всех добавленных стран
            cout << "========= Список страны =========" << endl;
            printObjects(countries);
            cout << "======================================" << endl;
            break;
        }
        case 8:
        {
            // Вывод всех добавленных фирм-изготовителей
            cout << "========= Список фирмы-изготовители =========" << endl;
            printObjects(manufacturers);
            cout << "===============================================" << endl;
            break;
        }
        case 9:
        {
            // Вывод всех добавленных марок автомобилей
            cout << "========= Список марки автомобилей =========" << endl;
            printObjects(carBrands);
            cout << "=================================================" << endl;
            break;
        }
        case 10:
        {
            // Вывод всех добавленных деталей
            cout << "========= Список детали =========" << endl;
            printObjects(parts);
            cout << "=======================================" << endl;
            break;
        }
        case 11:
        {
            // Вывод всех добавленных узлов
            cout << "========= Список узлы =========" << endl;
            printObjects(components);
            cout << "====================================" << endl;
            break;
        }
        case 12:
        {
            // Вывод всех добавленных агрегатов
            cout << "========= Список агрегаты =========" << endl;
            printObjects(assemblies);
            cout << "=======================================" << endl;
            break;
        }
        case 13:
        {
            string partName;
            cout << "Введите название детали, для которой нужно добавить альтернативы: ";
            cin >> partName;

            // Находим деталь по имени в векторе parts
            auto it = find_if(parts.begin(), parts.end(), [&partName](const Part& part) {
                return part.getName() == partName;
                });

            if (it != parts.end())
            {
                Part& targetPart = *it;

                bool addMoreAlternatives = true;
                while (addMoreAlternatives)
                {
                    string altPartName;
                    cout << "Введите название альтернативной детали (или введите 'exit' для завершения): ";
                    cin >> altPartName;

                    if (altPartName == "exit")
                    {
                        addMoreAlternatives = false;
                    }
                    else
                    {
                        targetPart.addAlternative(altPartName);
                    }
                }

                cout << "Альтернативные детали добавлены для '" << partName << "'." << endl;
            }
            else
            {
                cout << "Ошибка: Деталь '" << partName << "' не найдена." << endl;
            }
            break;
        }
        case 14:
        {
            string partName;
            cout << "Введите название детали, для которой нужно вывести альтернативы: ";
            cin >> partName;

            // Находим деталь по имени в векторе parts
            auto it = find_if(parts.begin(), parts.end(), [&partName](const Part& part) {
                return part.getName() == partName;
                });

            if (it != parts.end())
            {
                const Part& targetPart = *it;
                targetPart.printAlternatives();
            }
            else
            {
                cout << "Ошибка: Деталь '" << partName << "' не найдена." << endl;
            }
            break;
        }
        case 15:
        {
            string partName;
            cout << "Введите название детали, которую нужно заменить: ";
            cin >> partName;

            // Находим деталь по имени в векторе parts
            auto it = find_if(parts.begin(), parts.end(), [&partName](const Part& part) {
                return part.getName() == partName;
                });

            if (it != parts.end())
            {
                Part& targetPart = *it;

                string altPartName;
                cout << "Введите название альтернативной детали, которой нужно заменить '" << partName << "': ";
                cin >> altPartName;

                // Попытка замены выбранной детали на альтернативу
                if (targetPart.replaceWithAlternative(altPartName))
                {
                    // Успешно заменено
                    cout << "Деталь '" << partName << "' успешно заменена на альтернативу '" << altPartName << "'." << endl;

                    // Удаление использованной альтернативы из списка альтернативных деталей
                    targetPart.removeAlternative(altPartName);
                }
                else
                {
                    // Не удалось заменить
                    cout << "Ошибка: Не удалось заменить деталь '" << partName << "' на альтернативу '" << altPartName << "'." << endl;
                }
            }
            else
            {
                cout << "Ошибка: Деталь '" << partName << "' не найдена." << endl;
            }
            break;
        }
        case 16: 
        {
            string name;
            cout << "Введите имя работника автосервиса: ";
            cin >> name;
            users.push_back(new ServiceWorker(name));
            break;
        }
        case 17: 
        {
            string name;
            cout << "Введите имя работника магазина запчастей: ";
            cin >> name;
            users.push_back(new PartsStoreEmployee(name));
            break;
        }
        case 18: 
        {
            string name;
            cout << "Введите имя поставщика-оптовика: ";
            cin >> name;
            users.push_back(new WholesaleSupplier(name));
            break;
        }
        case 19:
            cout << "Информация о сотрудниках:" << endl;
            for (const auto& user : users) {
                cout << "Имя: " << user->getName() << endl;
                cout << "Роль: " << user->getRole() << endl;
                user->performTask(); 
                cout << "------------------------------------" << endl;
            }
            
            break;
        case 20:
            exitMenu = true;
            break;
        default:
            cout << "Неправильный выбор. Попробуйте еще раз." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}