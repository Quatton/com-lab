import { readFileSync } from "fs";
import { exit } from "process";
import { Resend } from "resend";

const resend = new Resend(Bun.env.RESEND_API_KEY);

const extension: Record<string, string> = {
  c: "C",
  scm: "S",
  py: "PY",
  s: "ASM",
};

const input = prompt("Which Kadai?");

if (!input) exit();

if (input in extension) {
  for (let i = 6; i <= 11; i++) void submitFromInput(`kadai${i}.${input}`);
} else {
  void submitFromInput(input);
}

async function submitFromInput(input: string) {
  const sp = input.split(" ");
  const f = sp.shift();
  const [filename, ext] = f!.split(".");
  if (!(ext in extension)) exit();

  const s = sp.shift();
  const section = s ? s.toUpperCase() : extension[ext];

  const [_, num] = filename.split("kadai");

  const attachments: Parameters<typeof resend.emails.send>[0]["attachments"] =
    [];

  try {
    const file = readFileSync(`../${section}/kadai${num}/kadai${num}.${ext}`);
    attachments.push({
      filename: `kadai${num}.${ext}`,
      content: file,
    });
  } catch (err) {
    // no file it's ok
  }

  try {
    const report = readFileSync(`../${section}/kadai${num}/report.txt`);
    attachments.push({
      filename: `report.txt`,
      content: report,
    });
  } catch (err) {
    // no report it's ok
  }

  try {
    const data = await resend.emails.send({
      from: Bun.env.FROM!,
      to: "isutbe2023@gmail.com",
      // to: "atomicatives@gmail.com",
      cc: Bun.env.CC!,
      subject: `${section}${num} ${Bun.env.DETAIL}`,
      text: `This is an automated submission email. Please contact ${Bun.env
        .CC!}.`,
      attachments,
    });

    console.log(data.id);
  } catch (e) {
    console.log(e);
  }
}
