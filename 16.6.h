//names_st.h   head file
#define SLEN 32
typedef struct names_st {
	char first[SLEN];
	char last[SLEN];
} names;

void getnames(names *);
void shownames(const names *);
