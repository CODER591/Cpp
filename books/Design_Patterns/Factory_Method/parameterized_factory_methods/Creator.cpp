class ProductId {
public:
  friend bool operator==(const ProductId &id1, const ProductId &id2);
};

bool operator==(const ProductId &id1, const ProductId &id2)
{
  return true;
}

class Product {};

class MyProduct : public Product {};
class YourProduct : public Product {};
class TheirProduct : public Product {};

const ProductId MINE;
const ProductId YOURS;
const ProductId THEIRS;

class Creator {
public:
    virtual Product* Create(ProductId);
};

Product* Creator::Create (ProductId id) {
    if (id == MINE)  return new MyProduct;
    if (id == YOURS) return new YourProduct;
    // repeat for remaining products...

    return 0;
}


class MyCreator : public Creator {
public:
    virtual Product* Create (ProductId id);
};

Product* MyCreator::Create (ProductId id) {
    if (id == YOURS)  return new MyProduct;
    if (id == MINE)   return new YourProduct;
        // N.B.: switched YOURS and MINE

    if (id == THEIRS) return new TheirProduct;

    return Creator::Create(id); // called if all others fail
}
