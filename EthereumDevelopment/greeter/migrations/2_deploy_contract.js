const greeter = artifacts.require("./greeter.sol");

module.exports = function (deployer) {
    deployer.deploy(greeter, ["Hi Hello", { gas: 67000000 }]);
};
