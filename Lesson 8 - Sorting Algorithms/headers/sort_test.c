


void insertionSort(List* list){
    Node* fu;
    Node* ls;
    Node* current;
    Node* trailing;

    if(list->head){
        ls = list->head;
    }
    while(ls->next){
        fu=ls->next;
        if(fu->entry < list->head->entry){
            ls->next = fu->next;
            fu->next = list->head;
            list->head = fu;
        }else{
            trailing = list->head;
            for(current = trailing->next; current->entry < fu->entry; current = current->next){
                trailing = current;
            }
            if(fu == current){
                ls = fu;
            }else{
                ls->next = fu->next;
                fu->next = current;
                trailing->next = fu;
            }
        }
    }
}