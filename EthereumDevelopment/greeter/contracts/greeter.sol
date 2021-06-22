// SPDX-License-Identifier: MIT
pragma solidity >=0.4.22 <0.9.0;

contract mortal {
  address owner;
  constructor() { owner = msg.sender; }

  function kill() public { if(msg.sender == owner) selfdestruct(owner); }
}

contract greeter is mortal {
    string greeting;

    function greeting (string _greeting) public {
        greeting = _greeting;
    }

    function setGreeting(string _greeting) public {
        greeting = _greeting;
    }

    function greet() constant returns (string) {
        return greeting;
    }
}