class Solution{
public:

bool parseBoolExpr(string expression) {
	int n = expression.size();
	stack<bool> operands;
	stack<char> operators;
	for(int i = 0; i<n; i++) {
		if(expression[i] == '!' || expression[i] == '&' || expression[i] == '|' || expression[i] == '(' || expression[i] == ',') {
			operators.push(expression[i]);
		}
		else if(expression[i] == 't' || expression[i] == 'f') {
			if(expression[i] == 't') operands.push(true);
			else operands.push(false);
		}
		else {
			// ')'
			int commas = 0;
			while(operators.top() != '(') {
				char curr_op =  operators.top();
				operators.pop();
				if(curr_op == ',') commas++;
			}
			operators.pop();
			char curr_op = operators.top();
			operators.pop();
			bool result;
			if(curr_op == '!') {
				result = !operands.top();
				operands.pop();
				operands.push(result);
				continue;
			}
			else if(curr_op == '&') {
				result = true;
			}
			else if(curr_op == '|') {
				result = false;
			}
			for(int i = 0; i<=commas; i++) {
				
				if(curr_op == '&') {
					result &= operands.top();
					operands.pop();
				}
				else if(curr_op == '|') {
					result |= operands.top();
					operands.pop();
				}
			}
			operands.push(result);
		}
	}
	return operands.top();
}
};