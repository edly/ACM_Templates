void Construct(){
	for (int i = 0; i < n; ++i){
		Node *p = &pool[ss++], *q = last;
		p->len = i + 1;
		for (; q && !q->ch[c[i]]; q = q->f) q->ch[c[i]] = p;
		last = p;
		if (!q) p->f = root; else
			if (q->len + 1 == q->ch[c[i]]->len) q->f = q->ch[c[i]]; else{
				Node *y = q->ch[c[i]], *r = &pool[ss++];
				*r = *y;
				r->len = q->len + 1;
				y->f = p->f = r;
				for (; q && q->ch[c[i]] == y; q = q->f) q->ch[c[i]] = r;
			}
	}
}

int main(){
	Construct();
	return 0;
}

