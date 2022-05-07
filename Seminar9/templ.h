template<typename K, typename V>
class Map{

    struct tuple{
        K key;
        V value;
        int index;
    };

private:
    tuple* array;
    int total;
    K lastAccess;

    bool exists(K key){
        for(int i = 0;i<this->total;i++){
            if (this->array[i].key == key) return true;
        }
        return false;
    }
    K getKey(int index) const{
        return this->array[index].key;
    }

public:
    Map(){
        this->array = new tuple[1000];
        this->total = 0;
    }

    Map& operator[](K element){
        this->lastAccess = element;
        return *this;
    }

    Map& operator=(V element){
        bool ok = false;
        for(int i=0;i<this->total;i++){
            if(this->array[i].key == this->lastAccess){
                this->array[i].value = element;
                ok = true;
                break;
            }
        }
        if(!ok){
            this->array[this->total].key = this->lastAccess;
            this->array[this->total].value = element;
            this->array[this->total].index = this->total;
            this->total++;
        }
        return *this;
    }

    void Set(K key, V value){
        bool ok = false;
        for(int i=0;i<this->total;i++){
            if(this->array[i].key == key){
                this->array[i].value = value;
                ok = true;
                break;
            }
        }
        if(!ok){
            this->array[this->total].key = key;
            this->array[this->total].value = value;
            this->array[this->total].index = this->total;
            this->total++;
        }
    }

    bool Get(const K& key, V& value){
        for(int i=0;i<this->total;i++){
            if(this->array[i].key == key){
                value = this->array[i].value;
                return true;
            }
        }
        return false;
    }

    int Count(){
        return this->total;
    }

    void Clear(){
        delete this->array;
        this->total = 0;
    }

    bool Delete(const K& key){
        for(int i=0;i<this->total;i++){
            if(this->array[i].key == key){
                for(int j = i; j <this->total;j++){
                    this->array[j] = this->array[j + 1];
                    this->array[j].index--;
                }
                this->total--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K,V>& map){
        if (this->total != map.total) return false;

        for(int i=0;i<map.total;i++){
            if (!this->exists(map.getKey(i))) return false;
        }
        return true;
    }


    tuple* begin(){
        return &this->array[0];
    }
    tuple* end(){
        return &this->array[this->total];
    }
};