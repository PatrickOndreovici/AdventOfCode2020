const fs = require('fs');

let data = fs.readFileSync('./input.txt', {encoding:'utf8', flag:'r'}); 

data = data.split("\r\n\r\n");

let rules = data[0].split('\r\n');

let vecini = {};
const parseRules = () => {
    for (let i = 0; i < rules.length; ++i){
        let aux = rules[i].split(': ');
        vecini[aux[0]] = aux[1];
    }
}

parseRules();


let dp = {};

const computeRegex = (val) => {
    if (vecini[val] === '"a"'){
        return 'a';
    }
    else if (vecini[val] === '"b"'){
        return 'b';
    }
    let r = vecini[val].split(' | ');
    let ans = "(";
    for (let i = 0; i < r.length; ++i){
        let aux = "";
        let v = r[i].split(' ');
        for (let j = 0; j < v.length; ++j){
            aux += computeRegex(v[j]);
        }
        ans += aux;
        if (i < r.length - 1){
            ans += '|';
        }
    }
    return ans + ")";
}


let contor = 0;

let messages = data[1].split('\r\n');

let rule42 = computeRegex(42);
let rule31 = computeRegex(31);

let rr = new RegExp("^" + rule42 + "+" + rule31 + "+$");

for (let i = 0; i < messages.length; ++i){
    let ok = false;
    if (!rr.test(messages[i])){
        continue;
    }
    for (let a = 1; a <= 30 && ok === false; ++a){
        for (let b = a - 1; b >= 0 && ok === false; --b){
            let regex = new RegExp("^" + rule42 + "{" + a + "}" + rule31 + "{" + b +"}$");
            if (regex.test(messages[i])){
                ok = true;
                break;
            }
        }
    }
    if (ok){
        ++contor;
    }
}

console.log(contor);