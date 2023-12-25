#include <stdio.h>
#include "calc3.h"
#include "build-artifacts/y.tab.h"

static int lbl;
int Initialize_value = 0;
//For declaring Label

void Initialize_data(){
    printf(".data\n");
    printf("a: .quad 0\n");
    printf("b: .quad 0\n");
    printf("c: .quad 0\n");
    printf("d: .quad 0\n");
    printf("e: .quad 0\n");
    printf("f: .quad 0\n");
    printf("g: .quad 0\n");
    printf("h: .quad 0\n");
    printf("i: .quad 0\n");
    printf("j: .quad 0\n");
    printf("k: .quad 0\n");
    printf("l: .quad 0\n");
    printf("m: .quad 0\n");
    printf("n: .quad 0\n");
    printf("o: .quad 0\n");
    printf("p: .quad 0\n");
    printf("q: .quad 0\n");
    printf("r: .quad 0\n");
    printf("s: .quad 0\n");
    printf("t: .quad 0\n");
    printf("u: .quad 0\n");
    printf("v: .quad 0\n");
    printf("w: .quad 0\n");
    printf("x: .quad 0\n");
    printf("y: .quad 0\n");
    printf("z: .quad 0\n");
    printf("GCDVA: .quad 0\n");
    printf("GCDVB: .quad 0\n");
    printf("factA: .quad 0\n");
    printf("factB: .quad 0\n");
    printf("factC: .quad 0\n");
    printf("lntwoA: .quad 0\n");
    printf("lntwoB: .quad 0\n");
    printf("\n");
    printf("format: .asciz \"%%d\\n\"\n");
    printf(".text\n");
    printf(".global main\n");
    printf("\n");
    printf("exit_program:\n");
    printf("\tmov $60, %%rax\n");
    printf("\txor %%rdi, %%rdi\n");
    printf("\tsyscall\n");
    printf("\n");
    lntwo_Function();
    printf("\n");
    fact_Function();
    printf("\n");
    GCD_Function();
    printf("\n");
    printf("main:\n");
}

void Compare(){
    printf("\tpopq %%rax\n");
    printf("\tpopq %%rbx\n");
    printf("\tcmpq %%rbx, %%rax\n");
}

void Set_Up(){
    printf("\tpopq %%rbx\n");
    printf("\tpopq %%rax\n");
}

void Print(){
    printf("\tpopq %%rsi\n");
    printf("\tpush %%rbx\n");
    printf("\tleaq format(%%rip), %%rdi\n");
    printf("\txor %%rax, %%rax\n");
    printf("\tcall printf@plt\n");
    printf("\tpop %%rbx\n");
}

void GCD_Function(){
    printf("GCD_function:\n");
    printf("\tpushq %%rdx\n");
    printf("\tpopq GCDVA(%%rip)\n");
    printf("\tpushq %%rcx\n");
    printf("\tpopq GCDVB(%%rip)\n");
    printf("LGCD0:\n");
    printf("\tmovq GCDVA(%%rip), %%rax\n");
    printf("\tmovq GCDVB(%%rip), %%rbx\n");
    printf("\tcmp %%rax, %%rbx\n");
    printf("\tje	LEX\n");
    printf("\tjg	LGCD1\n");
    printf("\tsub %%rbx, %%rax\n");
    printf("\tpushq %%rax\n");
    printf("\tpopq	GCDVA(%%rip)\n");
    printf("\tjmp	LGCD2\n");
    printf("LGCD1:\n");
    printf("\tsub %%rax, %%rbx\n");
    printf("\tpushq %%rbx\n");
    printf("\tpopq	GCDVB(%%rip)\n");
    printf("LGCD2:\n");
    printf("\tjmp	LGCD0\n");
    printf("LEX:\n");
    printf("\tmovq GCDVA(%%rip), %%rax\n");
    printf("\tret\n");
}

void fact_Function(){
    printf("fact_function:\n");
    printf("\tpushq %%rdx\n");
    printf("\tpopq\tfactA(%%rip)\n");
    printf("\tpushq\t$1\n");
    printf("\tpopq\tfactB(%%rip)\n");
    printf("\tpushq\tfactA(%%rip)\n");
    printf("\tpushq\t$0\n");
    printf("\tpopq\t%%rax\n");
    printf("\tpopq\t%%rbx\n");
    printf("\tcmpq\t%%rbx, %%rax\n");
    printf("\tjne\tLFACT1\n");
    printf("\tpushq\t$1\n");
    printf("\tpopq\tfactB(%%rip)\n");
    printf("\tjmp\tLFACT4\n");
    printf("LFACT1:\n");
    printf("\tpushq\t$1\n");
    printf("\tpopq\tfactB(%%rip)\n");
    printf("\tpushq\t$2\n");
    printf("\tpopq\tfactC(%%rip)\n");
    printf("LFACT2:\n");
    printf("\tpushq\tfactC(%%rip)\n");
    printf("\tpushq\tfactA(%%rip)\n");
    printf("\tpopq\t%%rax\n");
    printf("\tpopq\t%%rbx\n");
    printf("\tcmpq\t%%rbx, %%rax\n");
    printf("\tjl\tLFACT3\n");
    printf("\tpushq\tfactB(%%rip)\n");
    printf("\tpushq\tfactC(%%rip)\n");
    printf("\tpopq\t%%rbx\n");
    printf("\tpopq\t%%rax\n");
    printf("\tmulq\t%%rbx\n");
    printf("\tpushq\t%%rax\n");
    printf("\tpopq\tfactB(%%rip)\n");
    printf("\tpushq\tfactC(%%rip)\n");
    printf("\tpushq\t$1\n");
    printf("\tpopq\t%%rbx\n");
    printf("\tpopq\t%%rax\n");
    printf("\taddq\t%%rbx, %%rax\n");
    printf("\tpushq\t%%rax\n");
    printf("\tpopq\tfactC(%%rip)\n");
    printf("\tjmp\tLFACT2\n");
    printf("LFACT3:\n");
    printf("LFACT4:\n");
    printf("\tmovq factB(%%rip), %%rax\n");
    printf("\tret\n");
}

void lntwo_Function(){
    printf("lntwo_function:\n");
    printf("\tpushq\t%%rdx\n");
    printf("\tpopq\tlntwoA(%%rip)\n");
    printf("\tpushq\t$0\n");
    printf("\tpopq\tlntwoB(%%rip)\n");
    printf("LLNTWO0:\n");
    printf("\tpushq\tlntwoA(%%rip)\n");
    printf("\tpushq\t$1\n");
    printf("\tpopq\t%%rax\n");
    printf("\tpopq\t%%rbx\n");
    printf("\tcmpq\t%%rbx, %%rax\n");
    printf("\tjge\tLLNTWO1\n");
    printf("\tpushq\tlntwoA(%%rip)\n");
    printf("\tpushq\t$2\n");
    printf("\tpopq\t%%rbx\n");
    printf("\tpopq\t%%rax\n");
    printf("\tcqto\n");
    printf("\tidivq\t%%rbx\n");
    printf("\tpushq\t%%rax\n");
    printf("\tpopq\tlntwoA(%%rip)\n");
    printf("\tpushq\tlntwoB(%%rip)\n");
    printf("\tpushq\t$1\n");
    printf("\tpopq\t%%rbx\n");
    printf("\tpopq\t%%rax\n");
    printf("\taddq\t%%rbx, %%rax\n");
    printf("\tpushq\t%%rax\n");
    printf("\tpopq\tlntwoB(%%rip)\n");
    printf("\tjmp\tLLNTWO0\n");
    printf("LLNTWO1:\n");
    printf("\tmovq lntwoB(%%rip), %%rax\n");
    printf("\tret\n");
}

int ex(nodeType *p) {
    int lbl1, lbl2;
    if(Initialize_value==0){
        Initialize_data();
        Initialize_value=1;
    }
    if (!p) {
        return 0;
    }

    switch(p->type) {
    case typeCon:       
        printf("\tpushq\t$%d\n", p->con.value); 
        break;
    case typeId:        
        printf("\tpushq\t%c(%%rip)\n", p->id.i + 'a'); 
        break;
    case typeOpr:
        switch(p->opr.oper) {
        case WHILE:
            printf("L%03d:\n", lbl1 = lbl++);
            //For condition
            ex(p->opr.op[0]);
            //If false
            printf("\tL%03d\n", lbl2 = lbl++);
            //If true
            ex(p->opr.op[1]);
            printf("\tjmp\tL%03d\n", lbl1);
            //Jump back to same label
            printf("L%03d:\n", lbl2);
            break;
        case IF:
            //Condition
            ex(p->opr.op[0]);
            // Is it if or if else
            if (p->opr.nops > 2) {
                /* if else */
                printf("\tL%03d\n", lbl1 = lbl++);
                //Else
                ex(p->opr.op[1]);
                printf("\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                //If
                ex(p->opr.op[2]);
                printf("L%03d:\n", lbl2);
            } else {
                /* if */
                printf("\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("L%03d:\n", lbl1);
            }
            break;
        case PRINT:     
            ex(p->opr.op[0]);
            Print();
            break;
        case '=':       
            ex(p->opr.op[1]);
            printf("\tpopq\t%c(%%rip)\n", p->opr.op[0]->id.i + 'a');
            break;
        case UMINUS:    
            ex(p->opr.op[0]);
            printf("\tpop %%rdi\n");
            printf("\tnegq %%rdi\n");
            printf("\tpushq %%rdi\n");
            break;
	case FACT:
  	    ex(p->opr.op[0]);
        printf("\tpopq %%rdx\n");
        printf("\tcall fact_function\n");
	    printf("\tpushq %%rax\n");
	    break;
	case LNTWO:
	    ex(p->opr.op[0]);
        printf("\tpopq %%rdx\n");
        printf("\tcall lntwo_function\n");
	    printf("\tpushq %%rax\n");
	    break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            switch(p->opr.oper) {
            case GCD:           
                printf("\tpopq %%rdx\n");
                printf("\tpopq %%rcx\n");
                printf("\tcall GCD_function\n");
                printf("\tpushq %%rax\n"); 
                break;
            case '+':  Set_Up(); printf("\taddq %%rbx, %%rax\n");printf("\tpushq %%rax\n");  break;
            case '-':  Set_Up();printf("\tsubq %%rbx, %%rax\n");printf("\tpushq %%rax\n");  break; 
            //Result for Mul is in rax
            case '*':  Set_Up();printf("\tmulq %%rbx\n"); printf("\tpushq %%rax\n"); break;
            //rbx is denominator; Still need to handle the float value
            case '/':  Set_Up();printf("\tcqto\n");printf("\tidivq %%rbx\n");printf("\tpushq %%rax\n"); break;
            case '<':   Compare(); printf("\tjle"); break;
            case '>':   Compare(); printf("\tjge"); break;
            case GE: Compare(); printf("\tjg"); break;
            case LE: Compare(); printf("\tjl"); break;
            case NE: Compare(); printf("\tje"); break;
            case EQ: Compare(); printf("\tjne"); break;
            }
        }
    }

    return 0;
    }
