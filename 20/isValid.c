
typedef struct StackNode * stack;


struct StackNode{
    char val;
    struct StackNode *next;
};


stack createStack(){
    stack s;
    s = (stack) calloc(sizeof(struct StackNode), 1);
    s->next = NULL;
    
    return s;
}


void push(stack s, char val){
    struct StackNode * tmp;
    
    tmp = (struct StackNode *) calloc(sizeof(struct StackNode), 1);
    tmp->val = val;
    tmp->next = s->next;
    
    s->next = tmp;
  
}

char pop(stack s){
    
    struct StackNode *tmp;
    
    tmp = s->next;
    s->next = tmp->next;
    
    return tmp->val;
    
}

bool isEmptyStack(stack s){
    
    return s->next == NULL;
}

bool isCorrectParenthese(char p1, char p2){
    
    bool res = true;
    
    
    switch(p1){
    
        case '(':
            res = (p2 == ')');
            break;
        case '[':
            res = (p2 == ']');
            break;
        case '{':
            res = (p2 == '}');
            break;
 
    }
    
    return res;
}


bool isValid(char * s){

    char parenthese;
    int i;
    stack stk;
    
    stk = createStack();
    
    for (i = 0; s[i] != '\0'; i++){
        
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(stk, s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if (isEmptyStack(stk) == true )
                return false;
            else if (isCorrectParenthese(pop(stk), s[i]) == false){
                return false;

            }
        }
    }
    
    if (isEmptyStack(stk) == false)
        return false;
    return true;
    
    
}
