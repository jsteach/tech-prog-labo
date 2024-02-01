let project = new Project('test');

project.cmd = true;
project.addFile('sources/**');
project.setDebugDir('../Deployment');

resolve(project);