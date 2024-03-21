const fs = require('fs');



let project = new Project('TP1');

project.kore = false;
project.cmd = true;

project.addFile('Sources/**');
project.setDebugDir('../Deployment');

resolve(project);
